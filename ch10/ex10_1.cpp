#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <forward_list>
#include <cassert>
#include <stack>
#include <algorithm>
using namespace std;

int Count(vector<int>::iterator vecBegin, vector<int>::iterator vecEnd, int num)
{
	int cnt = 0;
	auto curr = vecBegin;
	for(curr; curr!=vecEnd; curr++)
	{
		if (*curr == num)
			cnt++;
	}
	return cnt;
}

int main()
{
	vector<int> vec;
	int tmp, SearchNum, result;
	cout << "Input number, end with 0" << endl;
	while(cin >> tmp && tmp != 0)
		vec.push_back(tmp);
	cout << "Input the number to search" << endl;
	cin >> SearchNum;
	result = Count(vec.begin(), vec.end(), SearchNum);
	cout<<"Find " << result << endl;
}
 
