#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <iostream>
using namespace std;

shared_ptr<vector<int>> ReturnVec()
{
    shared_ptr<vector<int>> vec = make_shared<vector<int>>();
    return vec;
}

shared_ptr<vector<int>> ReadStream(istream& in)
{
    shared_ptr<vector<int>> vec = ReturnVec();
    int temp;
    while(in >> temp)
        vec->push_back(temp);
    return vec;
}

void PrintVec(shared_ptr<vector<int>> vec)
{
    for(auto& e: *vec)
        cout << e << " ";
}

int main()
{
    cout << "输入值到vector" <<endl;
    shared_ptr<vector<int>> vec = ReadStream(cin);
    PrintVec(vec);
    return 0;
}