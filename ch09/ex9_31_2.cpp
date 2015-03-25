#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <forward_list>
#include <cassert>
using namespace std;

int main()
{
	forward_list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = vi.begin();
	auto pre = vi.before_begin();
	while(iter != vi.end()){
		if(*iter % 2){
			iter = vi.insert_after(iter, *iter);
			pre = iter; 
			iter++;
		}
		else{
			iter = vi.erase_after(pre);
		}
	}

	for(auto &i: vi)
		cout<<i<<endl;
}
 