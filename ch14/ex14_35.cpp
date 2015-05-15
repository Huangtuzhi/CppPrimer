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

class Function
{
public:
    Function(istream &o = cin): os(o) { }
    string operator()()
    {
        if (os >> s)
            return s;
        else
            return "";
    }
private:
    istream &os;
    string s;
};

int main()
{
    Function f;
    cout << f() << endl;
    return 0;
}