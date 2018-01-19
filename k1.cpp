// mach1.cpp : Defines the entry point for the console application.

#include <map>
#include "trie.cpp"
using namespace std;
template <typename T>string toString(T a)
{
	stringstream ss;
	ss << a;
	string g;
	ss >> g;
	return g;
}
void simulate1()//3:06 min 3.371GB
{
	trie<double> t;
	int i;
	int y;
	for (i = 1; i < 1000000; i++)t.insert(toString(i), i);
	for (i = 1; i < 1000000; i++)t.search(toString(i));
	for (i = 1; i < 1000000; i++)t.remove(toString(i));

}
void simulate2()//3:48 min 3.829GB
{
	int i;
	map<string, double>t;
	for (i = 1; i < 1000000; i++)t[toString(i)] = i;
	for (i = 1; i < 1000000; i++)t[toString(i)];
//	for (i = 1; i < 1000000; i++)t.erase(toString(i));
}
int main()
{
	simulate1();
	//simulate2();
	cout<<"finished\n";
	int y;
	cin>>y;
	//return 0;
}
