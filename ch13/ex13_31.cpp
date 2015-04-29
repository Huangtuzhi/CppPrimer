#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>
#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

class HasPtr{
friend void swap(HasPtr&, HasPtr&);
//重载 <运算符是为了调用<algorithm>中的sort运算
friend bool operator<(const HasPtr&, const HasPtr&);
public:
    //构造函数
    HasPtr(const string& s, int a = 100): ps(new string(s)), i(a){}
    //拷贝构造函数
    HasPtr(const HasPtr&);
    //拷贝赋值运算符
    HasPtr& operator=(const HasPtr&);
    void Printvari(){cout << *ps << " " << i << endl; }

    ~HasPtr(){ delete ps; }
private:
    string* ps;
    int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

inline bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{ 
    return lhs.i < rhs.i; 
}

HasPtr::HasPtr(const HasPtr& orig)
{
    i = orig.i;
    ps = new string(*orig.ps);
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto new_p = new string(*rhs.ps);
    delete ps; //删除之前的资源,比如下面的Old("tuzhi")
    this->ps = new_p; 
    this->i = rhs.i; 
    return *this;
}

int main()
{
    HasPtr p1("Huangyi", 80);
    HasPtr p2("xiaosi", 90);
    HasPtr p3("xiaosi", 70);

    vector<HasPtr> vec;
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);

    sort(vec.begin(), vec.end());

    //进行排序
    for(auto i: vec)
        i.Printvari();

    return 0;
}