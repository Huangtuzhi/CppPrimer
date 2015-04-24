#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>

using namespace std;

class StrBlob
{
public:
    StrBlob(): data(make_shared<vector<string>>()) { }
    StrBlob(initializer_list<string> il): 
        data(make_shared<vector<string>>(il)) { }
    int size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string& t) { data->push_back(t); }
    void pop_back();

    string& front();
    string& back();
private:
    shared_ptr<vector<string>> data;
    void check(int i, const string& msg) const;
};

void StrBlob::check(int i, const string& msg) const
{
    if(i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

int main()
{
    StrBlob Blob{"ltt","wy"};
    Blob.push_back("huangyi");
    cout << "front :" << Blob.front() << endl;
    cout << "size :" << Blob.size() << endl;

    StrBlob Blob2 = Blob;
    cout << "front :" << Blob2.front() << endl;
    cout << "size :" << Blob2.size() << endl;

    return 0;
}