#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <forward_list>
#include <cassert>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

bool elimDups(vector<string>& words)
{
	for(auto &i: words)
		cout << i <<" ";
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	cout<< "\n"<<"Words elimed\n";
	for(auto &i: words)
		cout << i <<" ";
	return true;
}

int main()
{
	vector<string> str;
	string tmp;
	while(cin>>tmp)
		str.push_back(tmp);
	elimDups(str);
}
 
