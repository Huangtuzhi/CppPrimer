#include <vector>
#include <list>
#include <cassert>
using namespace std;

bool compare(const list<int>& a, int listNum, const vector<int>& b, int vecNum)
{
	assert(listNum <= a.size() && vecNum <= b.size());
	auto iter1 =  a.begin();
	auto iter2 =  b.begin();
	for(int i=0; i<listNum; i++)
		iter1++;

	for(int i=0; i<vecNum; i++)
		iter2++;

	if(*iter1==*iter2)
		return true;
	return false;
}

int main()
{
	list<int> a = {1, 3, 3, 4};
	vector<int> b = {1, 2, 3, 4, 5};
	bool flag = compare(a, 4, b, 4);
	cout<<flag<<endl;
}
