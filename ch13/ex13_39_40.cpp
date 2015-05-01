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
class StrVec
{
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(initializer_list<string> il);
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }
    void reserve(size_t n);
private:
    static allocator<string> alloc;
    void chk_n_alloc()
    { if(size() == capacity()) reallocate(); }
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    string* elements;
    string* first_free;
    string* cap;
};

//静态成员在类外定义才能用，不然出现undefined reference to `StrVec::alloc'错误
allocator<string> StrVec::alloc; 

StrVec::StrVec(initializer_list<string> il)
{

    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void StrVec::push_back(const string& s)
{
    chk_n_alloc(); // 保证内存有空余的地方
    alloc.construct(first_free++, s); //在first_free的地方构造对象
}

void StrVec::reserve(size_t new_cap)
{
    if(new_cap < capacity()) 
        return;
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem =elements;
    for(size_t i=0; i!=size(); ++i)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if(elements)
    {
        for(auto p=first_free; p!=elements; )
            alloc.destroy(--p); // 对象进行析构
        alloc.deallocate(elements, cap - elements); //释放内存
    }
}

StrVec::StrVec(const StrVec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem =elements;
    for(size_t i=0; i!=size(); ++i)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

int main()
{
    StrVec vec{"huangyi", "huangjiahai", "baozhiyin"};
    vec.push_back("fuzi");
    vec.push_back("letian");
    vec.push_back("xiaosi");
    cout << "size: " << vec.size() << endl;
    cout << "begin: " << *vec.begin() << endl;
    cout << "end: " << *(vec.end()-1) << endl;

}


