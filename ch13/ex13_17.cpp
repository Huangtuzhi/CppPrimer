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

/*
//13.4
class numbered
{
friend void f(numbered);
public:
    numbered(){mysn = rand();}
private:
    int mysn;
};

void f(numbered s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}
//Result: 1804289383  1804289383  1804289383
*/

/*
//13.5
class numbered
{
friend void f(numbered);
public:
    numbered(){mysn = rand();}
    numbered(const numbered& rhs){mysn = rand();}
private:
    int mysn;
};

void f(numbered s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}
//Result: 1714636915 1957747793 424238335
*/

//13.6
class numbered
{
friend void f(const numbered&);
public:
    numbered(){mysn = rand();}
    numbered(const numbered& rhs){mysn = rand();}
private:
    int mysn;
};

void f(const numbered& s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}