#include <vector>
#include <set>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>
#include <exception>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
        bookNo(book), price(sales_price) {}
    virtual ~Quote() = default;
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const
    {
        return n * price;
    }
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote: public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p):
        Quote(book, p) {}
    double net_price(size_t n) const override
    {
        return n * price * 0.8;
    }
};

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
    << " #sold: " << n << "total due: " << ret <<endl;
    return ret;
}

int main()
{
    Quote A("11-22-33", 10.0);
    Bulk_quote B("11-22-34", 10.0);
    print_total(cout, A, 10);
    print_total(cout, B, 10);
    return 0;
}