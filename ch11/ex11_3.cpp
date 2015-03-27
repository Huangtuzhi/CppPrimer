#include <map>
#include <set>
#include <iostream>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	set<string> exclude_word = {"The", "but", "the"};
	string word;
	while (cin >> word){
		if (exclude_word.find(word) == exclude_word.end())
			word_count[word]++;
	}

	for(auto &i : word_count)
		cout << i.first << " occurs " << i.second
			<< ((i.second > 1) ? " times " : " time ") << endl;
}


