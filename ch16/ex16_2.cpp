#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>
#include <string.h>

using namespace std;

template <typename T, class Q>
int compare(const T &v1, const Q &v2)
{
	if (v1 < v2) return -1;
	else if (v1 > v2) return 1;
	return 0;
}

template <class T> T foo(T* p)
{
	T tmp = *p;
	return tmp;
}

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
	cout << "here" << endl;
	return strcmp(p1, p2);
}

int main()
{
	// vector<int> vec1{1, 2, 4};
	// vector<int> vec2{1, 2, 4};

	// int b = 11;
	// cout << foo(&b) << endl;
	// cout << compare(2, 2) << endl;
	// cout << compare(2.0, 2.0) << endl;
	// cout << compare(2, 2.0) << endl;
	// cout << compare('a', 'b') << endl;
	// cout << compare(vec1, vec2) << endl;
	cout << compare("huanhh", "huang") << endl;
}