#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
using namespace std;

class X
{
public:
    X() {cout << "X()" <<endl;}
    X(const X&) {cout << "X(const X&)" << endl;}
    X& operator=(const X& rhs) { cout << "operator=" << endl; return *this;}
    //operator= 并没有打印，这是因为编译器略过对拷贝构造函数的调用。
    ~X(){cout << "~X()" << endl;};   
};

void func(const X& a, X b)
{
    //vector<X> vec;
    //vec.push_back(a);
    //vec.push_back(b);
}

int main()
{
    X a;
    X b(a);
    func(a, b); //按这样会有三次析构，func的传值有个临时变量被析构。
    //X c = a;
    //X* ptr = new X(); 
    
    //delete ptr;
    return 0;
}