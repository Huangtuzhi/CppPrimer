#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <forward_list>
#include <cassert>
using namespace std;

bool FindString(forward_list<string>& list, string& str1, string& str2)
{
        forward_list<string>::iterator pre = list.before_begin();
        forward_list<string>::iterator curr = list.begin();
        for(curr;curr!=list.end();)
        {
                if(*curr == str1)
                {
                        curr = list.insert_after(curr, str2);
                        return true;
                }
                else
                {
                        pre = curr;
                        curr++;
                }

        }

        list.insert_after(pre, str2);
        return true;
}


int main()
{
        string str1("huang");
        string str2("xiaosi");
        forward_list<string> l = {"huangyi", "tuzhi", "rubi", "sunletian"};
        FindString(l, str1, str2);
        for(auto& i: l)
                cout<<i<<endl;
}

