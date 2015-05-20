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

    virtual void debug() const
    {
        cout << "Class Quote " << "bookNo:" << bookNo << " price:" << price << endl;
    }
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote: public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double price, size_t qty, double disc):
        Quote(book, price),
        quantity(qty), discount(disc) { }
    double net_price(size_t) const = 0;
protected:
    size_t quantity;
    double discount = 0.0; 
};

class Bulk_quote: public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, int lim, double dis):
        Disc_quote(book, p, lim, dis) {}
    double net_price(size_t n) const override
    {
        if (n > quantity)
            return n * price * discount;
        else
            return n * price;
    }

    // void debug() const
    // {
    //     cout << "Class Bulk_quote "
    //     << " limit:" << limit << " discount" << discount << endl;
    // }
};

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
    << " #sold: " << n << "total due: " << ret <<endl;
    // item.debug();
    return ret;
}

int main()
{
    Quote A("11-22-33", 10.0);
    Bulk_quote B("11-22-34", 10.0, 10, 0.8);
    print_total(cout, A, 10);
    print_total(cout, B, 20);
    print_total(cout, B, 10);
    return 0;
}
