#include <vector>
#include <string>
#include <list>
using namespace std;
int main()
{

list<char *> cStyle {"I", "am", "Huangyi"};
vector<string> cppStyle;
cppStyle.assign(cStyle.cbegin(), cStyle.cend());

/*C++11
for(const auto &it : cppStyle)
	cout<<it <<std::endl;
	*/

vector<string>::iterator it;
for(it=cppStyle.begin(); it!=cppStyle.end(); ++it)
cout<< *it<< std::endl;

return 0;
}


