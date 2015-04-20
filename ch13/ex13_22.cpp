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

    ~HasPtr(){
        delete ps;
    }
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
    auto new_p = new string(*rhs.ps);
    delete ps; //删除之前的资源,比如下面的Old("tuzhi")
    this->ps = new_p; 
    this->i = rhs.i; 
    return *this;
    
}

int main()
{
    HasPtr p("Huangyi");
    p.Printvari();

    p = p;
    p.Printvari();

    // HasPtr Old("tuzhi");
    // Old = p;
    // Old.Printvari();
    // p.Printvari();

    return 0;
}