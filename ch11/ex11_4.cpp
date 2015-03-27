#include <map>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	map<string, size_t> word_count;
	set<string> exclude_word = {"The", "but", "the"};
	string word;
	while (cin >> word){
		for(auto &ch : word)
			ch = tolower(ch);
		word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
		if (exclude_word.find(word) == exclude_word.end())
			word_count[word]++;
	}

	for(auto &i : word_count)
		cout << i.first << " occurs " << i.second
			<< ((i.second > 1) ? " times " : " time ") << endl;
}


