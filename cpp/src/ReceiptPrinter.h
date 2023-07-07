#ifndef CPP_RECEIPTPRINTER_H
#define CPP_RECEIPTPRINTER_H


#include "Receipt.h"

#include <iomanip>
#include <sstream>

class ReceiptPrinter
{
public:
    ReceiptPrinter(int columns = 40);
    std::string printReceipt(const Receipt &receipt);

private:
    std::string presentReceiptItem(const ReceiptItem &item) const;
    std::string presentDiscount(const Discount &discount) const;
    std::string presentTotal(const Receipt &receipt) const;

    std::string formatLineWithWhitespace(const std::string &name, const std::string &value) const;
    std::string presentPrice(double price) const;
    std::string presentQuantity(const ReceiptItem &item);
    std::string getFormattedNumberAsString(double number, int precision);

    int columns;
};

#endif //CPP_RECEIPTPRINTER_H
