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

int main()
{
	vector<int> vec= {1, 2, 3, 4, 5, 6, 7, 8, 9};
	fill_n(vec.begin(), vec.size(), 0);
	for(auto &i: vec)
		cout << i << " ";
}
 
