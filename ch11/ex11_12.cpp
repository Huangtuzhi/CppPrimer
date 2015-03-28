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
	pair<string, int> memo;
	vector<pair<string, int> > vec;
	cin >> memo.first;
	cin >> memo.second;
	vec.push_back(memo);

	auto i = vec.begin();
	cout << (*i).first << endl;
	cout << (*i).second << endl;
	return 0;
}


