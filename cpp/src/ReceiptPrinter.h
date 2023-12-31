#ifndef CPP_RECEIPTPRINTER_H
#define CPP_RECEIPTPRINTER_H


#include "Receipt.h"

#include <iomanip>
#include <sstream>
// Seprate defenition and implement of methods
// Improve Code Organization
class ReceiptPrinter
{

public:
    // Merge two constructor with defualt value
    ReceiptPrinter(int columns = 40);
    std::string printReceipt(const Receipt &receipt);

private:

    std::string presentReceiptItem(const ReceiptItem &item) const;
    std::string presentDiscount(const Discount &discount) const;
    std::string presentTotal(const Receipt &receipt) const;

    std::string formatLineWithWhitespace(const std::string &name, const std::string &value) const;
    static std::string presentQuantity(const ReceiptItem &item);
    static std::string getFormattedNumberAsString(double number, int precision = 2);

    const int columns;
    // Encapsulate String Constants
    static const std::string kNewLine;
    static const std::string kTotalPrefix;
    static const std::string kSpace;
    static const std::string kMultiplySign;
    static const std::string kOpenBracket;
    static const std::string kCloseBracket;
};


#endif //CPP_RECEIPTPRINTER_H
