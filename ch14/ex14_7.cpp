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

class String
{
    friend ostream& operator <<(ostream&os, const String& s);
public:
    String(): String("") { } //用String(const char*)初始化
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    ~String();

    const char* c_str() const { return elements; }
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements - 1; }

private:
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    char* elements;
    char* end;
    allocator<char> alloc;
};

ostream& operator <<(ostream& os, const String& s)
{
    os << "Size: " << s.size() << "\n";
    os << "Elements:";
    char* index = s.elements;
    while(*index){
        os << *index;
        index++;
    }
    return os;
}

pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
    auto str = alloc.allocate(e - b);
    return {str, uninitialized_copy(b, e, str)};
}

void String::range_initializer(const char* first, const char* last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char* s)
{
    char* s1 = const_cast<char*>(s);
    while(*s1)
        ++s1;
    range_initializer(s, ++s1); //包括/0转为string
}

String::String(const String& rhs)
{
    range_initializer(rhs.elements, rhs.end);
    //cout << "copy constructor" << endl;
}

void String::free()
{
    if (elements) {
        std::for_each(elements, end, [this](char &c){ alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }   
}

String& String::operator=(const String& rhs)
{
    auto newdata = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements =  newdata.first;
    end = newdata.second;
    return *this;
}

String::~String()
{
    free();
}

int main()
{
    
    String A;
    cout << A << endl;
    String B("huangyi");
    String C("fuzi");
    String D(B);
    String E = B;
    cout << B << endl;
    cout << C << endl;
    cout << D << endl;
    cout << E << endl;
    return 0;
}
