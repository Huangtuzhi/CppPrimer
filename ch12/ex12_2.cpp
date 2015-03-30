#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <iostream>

using namespace std;

class StrBob {
public:
    typedef vector<string>::size_type size_type;
    StrBob(): data(make_shared<vector<string>>()) {};
    StrBob(initializer_list<string> il): data(make_shared<vector<string>> (il)){}
    size_type size() const { return data->size(); };
    bool empty() const { return data->empty(); };
    
    void push_back(const string& t) { data->push_back(t); }
    void pop_back(){
    check(0, "pop_back on empty StrBob");
    data->pop_back();
    }
    
    string& front(){
    check(0, "front on empty StrBob");
    return data->front();
    }

    const string& front() const{
    check(0, "front on empty StrBob");
    return data->front();       
    }

    string& back(){
    check(0, "back on empty StrBob");
    return data->back();
    }

    const string& back() const{
    check(0, "back on empty StrBob");
    return data->back();
    }


private:
    shared_ptr<vector<string>> data;
    
    void check(size_type i, const string& msg) const{
    if (i >= data->size())
        throw out_of_range(msg);
    }
};

int main()
{
    StrBob huangyi{"hello", "world", "huangyi"};
    cout << huangyi.front() << " " << huangyi.back() << endl;
    huangyi.push_back("I love you");
    cout << huangyi.front() << " " << huangyi.back() << endl;
}