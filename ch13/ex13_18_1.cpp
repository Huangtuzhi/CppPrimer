#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <random>
using namespace std;

class PrivateCopy
{
friend void AccessThis();
public:
    PrivateCopy(){};
    ~PrivateCopy(){};
    void MemberAccess();
private:
    PrivateCopy(const PrivateCopy&);
    PrivateCopy& operator=(const PrivateCopy&);
};

void PrivateCopy::MemberAccess()
{
    PrivateCopy q;
    PrivateCopy p(q);
}

void AccessThis()
{
    PrivateCopy q;
    PrivateCopy p(q);
}

int main()
{
    PrivateCopy p;
    PrivateCopy q = p;  //q无法调用私有的成员函数
    //AccessThis();    //调用copy拷贝函数，但它未定义，产生链接错误。
    //p.MemberAccess();  //调用copy拷贝拷贝函数，但它未定义，产生链接错误。
}