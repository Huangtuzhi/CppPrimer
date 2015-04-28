#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>
#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
public:
    StrBlob(): data(make_shared<vector<string>>()) { }
    StrBlob(initializer_list<string> il): 
        data(make_shared<vector<string>>(il)) { }
    StrBlob(const StrBlob&);
    StrBlob& operator=(const StrBlob&);
    int size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string& t) { data->push_back(t); }
    void pop_back();

    string& front();
    string& back();

    StrBlobPtr begin();
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    void check(int i, const string& msg) const;
};

//class要接着写在后面
class StrBlobPtr
{
public:
    StrBlobPtr(): curr(0){ }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz) { }
    StrBlobPtr& operator ++(int) { this->curr++; }
    bool operator !=(const StrBlobPtr& rhs){
        return (this->curr != rhs.curr);
    }
    string& operator *(){
        auto p = check(curr, "dereference past end");
         return (*p)[curr];
    }
    string& deref() const;
    StrBlobPtr& incr();
private:
    shared_ptr<vector<string>> check(size_t i, const string& msg) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

//赋值构造函数
StrBlob::StrBlob(const StrBlob& orig)
{
    auto new_data = *(orig.data);
    data = make_shared<vector<string>>(new_data);
}

//赋值运算符
StrBlob& StrBlob::operator=(const StrBlob& orig)
{
    auto new_data = *(orig.data);
    data = make_shared<vector<string>>(new_data);
    return *this;
}

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

StrBlobPtr StrBlob::begin() 
{
    return StrBlobPtr(*this); //也调用第二个构造函数,因为有默认参数
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size()); //调用第二个构造函数
}

//用来检查vector是否还存在
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
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
    StrBlob Blob{"fuzi", "xiaosi", "letian", "weiye"};
    StrBlob Blob2;

    StrBlobPtr iter;
    for(iter=Blob.begin(); iter!=Blob.end(); iter++){
        cout << *iter << '\n';
    }

    Blob2 = Blob;
    for(iter=Blob2.begin(); iter!=Blob2.end(); iter++){
        cout << *iter << '\n';
    }   
    return 0;
}
