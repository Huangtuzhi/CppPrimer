#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <forward_list>
#include <cassert>
#include <stack>
#include <algorithm>
using namespace std;

int Count(list<string>::iterator vecBegin, list<string>::iterator vecEnd, string str)
{
	int cnt = 0;
	auto curr = vecBegin;
	for(curr; curr!=vecEnd; curr++)
	{
		if (*curr == str)
			cnt++;
	}
	return cnt;
}

int main()
{
	list<string> vec;
	string SearchString;
	string tmp;
	int result;
	cout << "Input string, end with 0" << endl;
	while(cin >> tmp)
		vec.push_back(tmp);
	cout << "Input the string to search" << endl;
	//cin >> SearchString;
	result = Count(vec.begin(), vec.end(), "tuzhi");
	cout<<"Find " << result << endl;
}
 
