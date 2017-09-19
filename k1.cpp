// mach1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "trie.h"
using namespace std;
template <typename T>string toString(T a)
{
	stringstream ss;
	ss << a;
	string g;
	ss >> g;
	return g;
}
void simulate1()//3:38 min 3.371GB
{
	trie<double> t;
	int i;
	int y;
	for (i = 1; i < 50000; i++)t.insert(toString(i), i);
	for (i = 1; i < 50000; i++)t.search(toString(i));
	for (i = 1; i < 50000; i++)t.remove(toString(i));
	cout << "yo1\n";
	cout << t.search("1234")<<endl;
	vector<double>V = t.peek("123");
	for (i = 0; i < V.size(); i++)cout << V[i] << "\n";
	cout << "yo2\n";
	cin >> y;
}
void simulate2()//3:48 min 3.829GB
{
	int i;
	map<string, double>t;
	for (i = 1; i < 50000000; i++)t[toString(i)] = i;
	for (i = 1; i < 50000000; i++)t[toString(i)];
	for (i = 1; i < 50000000; i++)t.erase(toString(i));
}
int main()
{
	simulate1();
	return 0;
}
