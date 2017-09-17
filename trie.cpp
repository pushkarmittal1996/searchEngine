#pragma once

#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>
#ifndef trie_cpp

void error(int id = -1, std::string g = "")
{
	if (id == -1)return;
	g = "ERROR " + g;
	std::cout << g << " " << id << "\n";
}

template<class T>class trie_node
{
	public:std::map<char, trie_node<T>* >M;
	T id;
	int ct;
	public:trie_node(T i)
	{
		id = i;
		ct = 1;
		M.clear();
	}
	public:trie_node()
	{
		M.clear();
		ct = 0;
		id = (T)0;
	}
	private:void remove(trie_node<T>*tn)
	{
		if (tn != NULL)
		{
			for (auto it : tn->M)
				remove(it.second);
			delete tn;
		}
	}
	public:~trie_node()
	{
		/*for (auto it:M)
		{
			remove(it.second);
		}*/
	}
};
template<class T>class trie
{
private:trie_node<T> * m;
public:trie()
{
	m = new trie_node<T>();
}
private:void Insert(std::string &g, T id, int i, std::map<char, trie_node<T>* > &M)
{
	if (i == g.size() - 1)
	{
		if (M.find(g[i]) != M.end())
		{
			trie_node <T>* tn = M[g[i]];
			if (tn->id != id&& tn->id != (T)0)
				error(-1, "Name Already used");
			else
				tn->id = id;
		}
		else
			M[g[i]] = new trie_node<T>(id);
		return;
	}
	if (M.find(g[i]) == M.end())
		M[g[i]] = new trie_node<T>();
	trie_node <T>* tn = M[g[i]];
	tn->ct++;
	Insert(g, id, i + 1, tn->M);
}
public:void insert(std::string g, T id)
{
	Insert(g, id, 0, m->M);
}
private:T Search(std::string &g, int i, std::map<char, trie_node<T>* > &M)
{
	if (M.find(g[i]) == M.end())
		return (T)0;
	if (i == g.size() - 1)
		return M[g[i]]->id;
	return Search(g, i + 1, M[g[i]]->M);
}
public:T search(std::string g)
{
	return Search(g, 0, m->M);
}
private:void Remove(std::string &g, int i, std::map<char, trie_node<T>* > &M)
{
	if (M.find(g[i]) == M.end() || i >= g.size())
		return;
	trie_node <T>* tn = M[g[i]];
	tn->ct--;
	Remove(g, i + 1, tn->M);
	if (tn->ct == 0)
	{
		delete tn;
		M.erase(g[i]);
	}
}
public:void remove(std::string g)
{
	Remove(g, 0, m->M);
}
private:void removeall(trie_node<T> *m)
{
	if (m == NULL)return;
	typename std::map<char, trie_node<T>* > ::iterator it;
	for (it = m->M.begin(); it != m->M.end(); it++)
	{
		removeall((*it).second);
	}
	delete m;
}
private:void Peek(std::string &g, int i, trie_node<T>* m, std::vector<T>&V)
{
	V.push_back(m->id);
	typename std::map<char, trie_node<T>* > ::iterator it;
	for (it = m->M.begin(); it != m->M.end(); it++)
	{
		if ((*it).second != NULL)
		{
			Peek(g, i + 1, (*it).second, V);
		}
	}
}
public: std::vector<T> peek(std::string g)
{
	std::vector<T>V;
	trie_node <T> *M;
	M = m;
	bool b = 1;
	for (int i = 0; i<g.size(); i++)
	{
		if (M->M.find(g[i]) != M->M.end())
		{
			M = M->M[g[i]];
		}
		else
		{
			b = 0;
			break;
		}
	}
	if (b == true)
		Peek(g, 0, M, V);
	return V;
}
public:~trie()
{
	removeall(m);
}
};
#endif

