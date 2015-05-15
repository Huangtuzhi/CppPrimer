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
    void operator()()
    {
        string s;
        while (os >> s)
            vec.push_back(s);
    }
private:
    istream &os;
public:
    vector<string> vec;
};

int main()
{
    Function f;
    f();
    for(auto i: f.vec)
        cout << i << endl;
    return 0;
}