#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>
#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

class HasPtr{
friend void swap(HasPtr&, HasPtr&);
public:
    //构造函数
    HasPtr(const string& s): ps(new string(s)), i(100){}
    //拷贝构造函数
    HasPtr(const HasPtr&);
    //拷贝赋值运算符
    HasPtr& operator=(const HasPtr&);
    void Printvari(){cout << *ps << " " << i << endl; }

    ~HasPtr(){ delete ps; }
private:
    string* ps;
    int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

HasPtr::HasPtr(const HasPtr& orig)
{
    i = orig.i;
    ps = new string(*orig.ps);
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto new_p = new string(*rhs.ps);
    delete ps; //删除之前的资源,比如下面的Old("tuzhi")
    this->ps = new_p; 
    this->i = rhs.i; 
    return *this;
    
}

int main()
{
    HasPtr p("Huangyi");
    HasPtr q("xiaosi");
    swap(p, q);
    p.Printvari();
    q.Printvari();

    return 0;
}