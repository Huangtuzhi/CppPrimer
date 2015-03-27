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

size_t Morethan6(vector<string>& vec)
{
	return count_if(vec.begin(), vec.end(), 
		[](const string& s){return s.size() > 6;});
}

int main()
{
	/*
	//ex 10.20
	vector<string> words{"asdfghg","qw","wrwqerqewrq","sdgads","af","dfg","bc","bnc"};	
	cout << "length > 6:" << Morethan6(words);
	*/

    //ex 10.21
	int loc = 8;
    auto check_and_decrease = [&loc](){return --loc ? false: true;};
	while(!check_and_decrease())
	{
		cout << "The value of variable:" << loc << "\n";
	}
	return 0;
}


