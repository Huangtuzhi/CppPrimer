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

class HasPtr{
public:
    //构造函数
    HasPtr(const string& s): ps(new string(s)), i(100){}
    //拷贝构造函数
    HasPtr(const HasPtr&);
    //拷贝赋值运算符
    HasPtr& operator=(const HasPtr&);
    void Printvari(){cout << *ps << " " << i << endl; }

private:
    string* ps;
    int i;
};

HasPtr::HasPtr(const HasPtr& orig)
{
    i = orig.i;
    ps = new string(*orig.ps);
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    this->i = rhs.i; 
    this->ps = new string(*rhs.ps);
}

int main()
{
    HasPtr p("Huangyi");
    p.Printvari();

    HasPtr q = p;
    q.Printvari();
    return 0;
}