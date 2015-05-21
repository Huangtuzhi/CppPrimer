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

    Quote(const Quote&rhs)
    {
        cout << "Quote class:copy constructor" << endl;
        bookNo = rhs.bookNo;
        price = rhs.price;
    }
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
    Bulk_quote(const string& book, double p, int lim, double dis):
        Quote(book, p), limit(lim), discount(dis) {}
    Bulk_quote(const Bulk_quote& rhs): 
        Quote(rhs), limit(rhs.limit), discount(rhs.discount) 
    {
        cout << "Bulk_quote class:copy constructor" << endl;
    }
    double net_price(size_t n) const override
    {
        if (n > limit)
            return n * price * discount;
        else
            return n * price;
    }
private:
    int limit;
    double discount;
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
    Bulk_quote B("11-22-34", 10.0, 10, 0.8);
    print_total(cout, A, 10);
    print_total(cout, B, 20);
    print_total(cout, B, 10);

    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("11-22-35", 10.0));
    basket.push_back(make_shared<Bulk_quote>("11-22-36", 10.0, 9, 0.8));
    // cout << basket.back()->net_price(10) << endl;
    print_total(cout, *basket.back(), 10);
    return 0;
}
