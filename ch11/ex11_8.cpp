#include <map>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	set<string> key;
	vector<string> dictionary;
	string word;
	while(cin >> word)
	{
		if(key.find(word) == key.end())
			dictionary.push_back(word);
		key.insert(word);

	}

	for(auto it : dictionary)
		cout << it << "\n";
}


