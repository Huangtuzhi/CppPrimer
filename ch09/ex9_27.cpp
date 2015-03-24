#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <forward_list>

using namespace std;

bool rmOddNumber(forward_list<int>& list)
{
	forward_list<int>::iterator pre = list.before_begin();
	forward_list<int>::iterator curr = list.begin();
	for(curr;curr!=list.end();)
	{
		if(*curr % 2) 
		{
			curr = list.erase_after(pre);
		}
		else
		{
			pre = curr;
			curr++;
		}

	}
	return true;
}

int main()
{
	forward_list<int> ele = {1, 2, 3, 4, 5, 0, 1, 2, 3, 9};
	rmOddNumber(ele);
	for(auto &i: ele)
		cout<<i<<endl;
}

