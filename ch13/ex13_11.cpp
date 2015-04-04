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
    HasPtr(const HasPtr& orig):
        ps(new string(*orig.ps)), i(orig.i){};
    HasPtr(const string& s = string()): 
        ps(new string(s)), i(0){}
    HasPtr& operator=(const HasPtr& rhs)
    {
        string* new_ps = new string(*rhs.ps);
        delete ps;
        this->i = rhs.i;
        this->ps = new_ps;
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }
    void Printvari(){cout << *ps << " " << i << endl;}
private:
    string* ps;
    int i;
};

int main()
{
    HasPtr p("Huangyi");
    HasPtr q;
    q = p;
    p.Printvari();
    q.Printvari();
    return 0;
}