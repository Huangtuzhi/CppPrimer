#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <iostream>

using namespace std;


vector<int>* ReturnVec()
{
    vector<int> *vec = new vector;
    return vec;
}

vector<int>* ReadStream(iostream& in)
{
    vector<int>* vec = ReturnVec();
    int temp;
    while(in >> temp)
        vec->push_back(temp);
    return vec;
}

Print(vector<int>* vec)
{
    for(auto& e: *vec)
        cout << e << " ";
    delete(vec);
}

int main()
{
    cout << "输入值到vector" <<endl;
    vector<int>* vec = ReadStream(cin);
    Print(vec);
    return 0;
}