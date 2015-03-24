#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <forward_list>
#include <cassert>
using namespace std;

bool FindString(forward_list<string>& list, const string& str1, const string& str2)
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
        FindString(l, "tuzhi", "awesome");
        //当FindString中str1用const时才可以采取上面的写法，因为"tuzhi"是一个临时变量，转瞬即逝。
        //http://blog.csdn.net/zhenwo123/article/details/8031155
        for(auto& i: l)
                cout<<i<<endl;
}

