// mach1.cpp : Defines the entry point for the console application.
//
#include "trie.cpp"
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

//#include <omp.h>

using namespace std;
template <typename T>string toString(T a)
{
	stringstream ss;
	ss << a;
	string g;
	ss >> g;
	return g;
}
void simulate()
{
	trie<double> t;
	int i;
	int k;
	//cin >> k;
	for (i = 1; i<100000; i++)
	{
		t.insert(toString(i), i);
	}
	//cin >> k;
	for (i = 1; i<100000; i++)
	{
		t.remove(toString(i));
	}
	//cin >> k;
}
int main()
{
	int t;
	//cin >> t;
	simulate();
	simulate();
	//cin >> t;
	//_CrtDumpMemoryLeaks();
	//cin >> t;
	return 0;
}
