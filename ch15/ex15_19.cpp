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

class Base
{
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

class Pub_Derv: public Base
{
    void memfcn(Base &b) { b = *this;}
    int f() { return prot_mem;}
};

class Prot_Derv: protected Base
{
    void memfcn(Base &b) { b = *this;}
    int f1() const { return prot_mem;}
};

class Priv_Derv: private Base
{
    void memfcn(Base &b) { b = *this;}
    int f1() const { return prot_mem;}
};

class Derived_from_Public: public Pub_Derv
{
    void memfcn(Base &b) { b = *this;}
    int use_base() {return prot_mem;}
};

class Derived_from_Protected: public Prot_Derv
{
    void memfcn(Base &b) { b = *this;}
    int use_base() {return prot_mem;}
};

//error :  ‘int Base::prot_mem’ is protected
class Derived_from_Private: public Priv_Derv
{
    // void memfcn(Base &b) { b = *this;} //illegal
    // int use_base() {return prot_mem;}
};


int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Protected dd2;
    Derived_from_Private dd3;

    // Base* p = &d1;
    // p = &d2;  //(X)
    // p = &d3; //(X)
    // p = &dd1;
    // p = &dd2; //(X)
    // p = &dd3; //(X)
    return 0;
}
