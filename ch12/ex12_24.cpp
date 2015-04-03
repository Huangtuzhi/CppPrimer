#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <fstream>
#include <iostream>
#include <exception>
using namespace std;

int main()
{
    cout << "输入字符串" << endl;
    string str;
    cin >> str;
    size_t len = str.size();
    char* result = new char[len];
    for(size_t i = 0; i < str.size(); i++)
        result[i] = str[i];

    cout << result << endl;
    delete[] result;
}