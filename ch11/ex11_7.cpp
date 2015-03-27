#include <map>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	map<string, vector<string>> families;
	string firstname;
	string lastname;
	cout << "输入家庭姓氏：" << endl;
	cin >> firstname;
	cout << "输入名字：" << endl;
	while(cin >> lastname)
	{
		cout << "输入名字："<<endl;
		families[firstname].push_back(lastname);
	}

	for(auto it: families){	
		cout << it.first ;
		for(auto e: it.second)
			cout << e << endl;
	}
}


