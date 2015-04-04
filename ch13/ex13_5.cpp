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
    HasPtr(const HasPtr&);
    HasPtr(const string& s = string()): 
        ps(new string(s)), i(0){}
    void Printvari(){cout << *ps;}
private:
    string* ps;
    int i;
};

HasPtr::HasPtr(const HasPtr& orig)
{
    i = orig.i;
    ps = new string(*orig.ps);
}

int main()
{
    HasPtr p("Huangyi");
    p.Printvari();
    return 0;
}