#include <map>
#include <set>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <utility>

using namespace std;

int main()
{
    map<string, size_t> word_count;
    string word;
    while(cin >> word){
        auto ret = word_count.insert({word, 1});
        if(!ret.second)
            ++ret.first->second;
    }

    for(auto i: word_count)
        cout << i.first << i.second << endl;
}

