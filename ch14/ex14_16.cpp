#include <vector>
#include <set>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>
#include <exception>
#include <iostream>
#include <fstream>
using namespace std;

class Sales_data {
    friend istream& operator>>(istream&, Sales_data&);
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);
    friend bool operator!=(const Sales_data& lhs, const Sales_data& rhs);

public:
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(n*p){}
    Sales_data() : Sales_data("", 0, 0.0f){}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f){}
    Sales_data(std::istream &is);

    Sales_data& operator+=(const Sales_data&); // compound-assignment
    std::string isbn() const { return bookNo; }

private:
    inline double avg_price() const;

    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}

Sales_data::Sales_data(std::istream &is) : Sales_data()
{
    is >> *this;
}


istream& operator>>(istream& is, Sales_data& item)
{
    double price = 3.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

ostream& operator<<(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs)
{
    return lhs.isbn()==rhs.isbn() && 
           lhs.units_sold==rhs.units_sold && 
           lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs)
{
    return !(lhs == rhs);
}

int main()
{
    Sales_data Day1("1", 100, 10);
    Sales_data Day2("2", 200, 10);
    Sales_data Day3("2", 200, 10);
    cout << Day1 << endl;
    cout << Day2 << endl;
    Sales_data in;
    cout << "bookNo |" << " units_sold" << endl;
    cin >> in;
    cout << in << endl;

    if(Day2 == Day3) cout << "Day2 == Day3" << endl;
}
