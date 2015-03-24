#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <cassert>
#include <deque>
using namespace std;

int main()
{
	string data;
	deque<string> DataQueue;
	cout<<"Enter strings"<<endl;
	while(cin>>data && data !="end")
		DataQueue.push_back(data);

	deque<string>::iterator it = DataQueue.begin();
	for(it; it!=DataQueue.end(); it++)
		cout<<*it<<endl;
}

 
