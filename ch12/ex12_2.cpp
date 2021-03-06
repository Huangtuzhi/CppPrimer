#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>

using namespace std;

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() 
    {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
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

class StrBlobPtr
{
public:
    StrBlobPtr(StrBlob &a): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz) { }
    string& deref() const;
    StrBlobPtr& incr();
private:
    shared_ptr<vector<string>> check(size_t i, const string& msg) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

//用来检查vector是否还存在
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{//第二个arg必须加const
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbounded StrBlobPtr");
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
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

    //cout << Blob.begin().deref();

    return 0;
}



