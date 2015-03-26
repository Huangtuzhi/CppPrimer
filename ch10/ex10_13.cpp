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

bool Morechars(string str)
{
	return str.size() >=5;
}

int main()
{
	vector<string> vec = {"ab", "abc", "abcde", "abcdef", "abcdefgh", "jhkjh", "lkjh", "adf", "ad", "g"};
	auto r = partition(vec.begin(), vec.end(), Morechars);
	for(auto i = vec.begin(); i != r; i++)
		cout << *i << " ";
}
 
