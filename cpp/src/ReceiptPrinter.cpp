#include "ReceiptPrinter.h"

ReceiptPrinter::ReceiptPrinter(int columns = 40) : columns(columns)
{
}

std::string ReceiptPrinter::printReceipt(const Receipt &receipt)
{
    std::string result;
    for (const auto &item : receipt.getItems())
    {
        result += presentReceiptItem(item);
    }
    for (const auto &discount : receipt.getDiscounts())
    {
        result += presentDiscount(discount);
    }
    result+= "\n";
    result += presentTotal(receipt);
    return result;
}

std::string ReceiptPrinter::presentReceiptItem(const ReceiptItem &item) const
{
    std::string price = getFormattedNumberAsString(item.getTotalPrice());
    std::string name = item.getProduct().getName();

    std::string line = formatLineWithWhitespace(name, price);

    if (item.getQuantity() != 1)
    {
        line += "  " + getFormattedNumberAsString(item.getPrice()) + " * " + presentQuantity(item) + "\n";
    }
    return line;
}

std::string ReceiptPrinter::presentDiscount(const Discount &discount) const
{
    std::string name = discount.getDescription() + "(" + discount.getProduct().getName() + ")";
    std::string pricePresentation = getFormattedNumberAsString(discount.getDiscountAmount());
    return formatLineWithWhitespace(name, pricePresentation);
}

std::string ReceiptPrinter::presentTotal(const Receipt &receipt) const
{
    std::string total = "Total: ";
    std::string pricePresentation = getFormattedNumberAsString(receipt.getTotalPrice());
    return formatLineWithWhitespace(total, pricePresentation);
}

std::string ReceiptPrinter::formatLineWithWhitespace(const std::string &name, const std::string &value) const
{
    int whitespaceSize = columns - name.length() - value.length();
    std::string whitespace;
    for (int i = 0; i < whitespaceSize; i++)
    {
        whitespace += " ";
    }
    return name + whitespace + value + "\n";
}


std::string ReceiptPrinter::presentQuantity(const ReceiptItem &item)
{
    return ProductUnit::Each == item.getProduct().getUnit()
               ? getFormattedNumberAsString(item.getQuantity(), kQuantityPrecision)
               : getFormattedNumberAsString(item.getQuantity(), kQuantityDecimalPrecision);
}


std::string ReceiptPrinter::getFormattedNumberAsString(double number, int precision = kDefualtPrecision)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << number;
    return stream.str();
}