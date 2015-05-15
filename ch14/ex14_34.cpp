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
    int operator()(bool a, int b, int c)
    {
        return a ? b : c;
    }
};

int main()
{
    Function f;
    cout << f(0, 10, -10);
    return 0;
}