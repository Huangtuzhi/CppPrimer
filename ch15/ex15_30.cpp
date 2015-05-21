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

class Basket
{
public:
    void addItem(const shared_ptr<Quote> &sale)
    { items.insert(sale); }
    double total_receipt(ostream&) const;

private:
    static bool compare(const shared_ptr<Quote> &lhs,
                        const shared_ptr<Quote> &rhs)
    { return lhs->isbn() < rhs->isbn(); }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;
    for(auto iter = items.cbegin();
        iter != items.cend();
        iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }

    // for(auto it: items)
    //     sum += print_total(os, *it, 1);
    os << "Total Sale: " << sum << endl;
    return sum;
}

int main()
{
    // Quote A("11-22-33", 10.0);
    // Bulk_quote B("11-22-34", 10.0, 10, 0.8);
    // print_total(cout, A, 10);
    // print_total(cout, B, 20);
    // print_total(cout, B, 10);

    // vector<shared_ptr<Quote>> basket;
    // basket.push_back(make_shared<Quote>("11-22-35", 10.0));
    // basket.push_back(make_shared<Bulk_quote>("11-22-36", 10.0, 9, 0.8));
    // print_total(cout, *basket.back(), 10);

    Basket basket;
    basket.addItem(make_shared<Quote>("11-22-35", 20.0));
    basket.addItem(make_shared<Quote>("11-22-35", 20.0));
    basket.addItem(make_shared<Bulk_quote>("11-22-36", 20.0, 9, 0.8));
    basket.total_receipt(cout);    

    return 0;
}