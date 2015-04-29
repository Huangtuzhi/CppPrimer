#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>
#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

class HasPtr
{
public:

    HasPtr(const string& s):
        ps(new string(s)), i(0), use(new int(1)){ }
    HasPtr(const HasPtr& p):
        ps(p.ps), i(p.i), use(p.use){ ++*use; }
    HasPtr& operator=(const HasPtr& rhs);
    ~HasPtr();
    void Print(){ cout << *ps << " : " << *use << endl; }
private:
    string* ps;
    int i;
    int* use;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    ++*rhs.use;
    if(--*use == 0){
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr()
{
    if(--*use == 0){
        delete ps;
        delete use;
    }
}

int main()
{
    // HasPtr Old("tuzhi");
    // Old.Print();
    // HasPtr New = Old;
    // Old.Print();
    // New.Print();
    // HasPtr New2 = New;
    // Old.Print();
    // New.Print();
    // New2.Print();

    //自赋值
    HasPtr Old("me");
    Old.Print();
    HasPtr New = Old;
    New.Print();

    HasPtr NewString("he");
    Old = NewString; //Old的引用计数要减掉
    Old.Print();
    New.Print();
    NewString.Print();

    return 0;
}