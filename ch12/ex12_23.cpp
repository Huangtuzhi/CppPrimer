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
    const string str1 = "huangyi";
    const string str2 = "wangrubi";

    unique<char []> result(new char[100]);
    string str = str1 + str2;
    for(size_t i = 0; i < str.size(); i++)
        result[i] = str[i];
    
}