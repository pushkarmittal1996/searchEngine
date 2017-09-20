#pragma once
#include <utility>
#include <iostream>
#include <iterator>
#include <vector>
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
	public:std::vector<std::pair<char, trie_node<T>* > >M;
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
	public:void remove(char c)
	{
		int low = 0;
		int high = M.size() - 1;
		int mid;
		while (low <= high)
		{
			mid = low + ((high - low) / 2);
			if (M[mid].first == c)
				break;
			else if (M[mid].first < c)
				low = mid + 1;
			else
				high = mid - 1;
		}
		if (mid < 0 || mid >= M.size())
			return;
		if (M[mid].first == c)
		{
			delete M[mid].second;
			for (int i = mid; i < M.size()-1; i++)
				M[i] = M[i+1];
			M.pop_back();
		}
	}
	public:	trie_node <T> * insert(char c)
	{
		if (M.size() == 0)
		{
            std::pair<char,trie_node <T>* >P;
            P.first = c;
            P.second = new trie_node <T> ();
			M.push_back(P);
			return M[0].second;
		}
		int low = 0;
		int high = M.size() - 1;
		int mid;
		while (low <= high)
		{
			mid = low + ((high - low) / 2);
			if (M[mid].first == c)
				return M[mid].second;
			else if (M[mid].first < c)
				low = mid + 1;
			else
				high = mid - 1;
		}
		std::pair<char, trie_node<T> * >P;
		P.first = c;
		P.second = new trie_node<T>();
		if (M[mid].first > c)
			mid--;
		M.push_back(P);
		if (mid == M.size() - 2)
		{
			return M[M.size() - 1].second;
		}
		for (int i = M.size() - 1; i > mid+1; i--)
			M[i] = M[i - 1];
		M[mid+1] = P;
		return M[mid+1].second;
	}
	public: trie_node <T> * search(char c)
	{
		int low = 0;
		int high = M.size()-1;
		int mid;
		while (low <= high)
		{
			mid = low + ((high - low) / 2);
			if (M[mid].first == c)
				return M[mid].second;
			else if (M[mid].first < c)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return NULL;
	}
};
template<class T>class trie
{
	private: trie_node<T> * m;
	public:trie()
	{
		m = new trie_node<T>();
	}
	private:void Insert(std::string &g, T id, int i, trie_node<T> * M)
	{
		if (m == NULL)return;
		trie_node <T>* tn = M->insert(g[i]);
		tn->ct++;
		if (i == g.size() - 1)
		{
			tn->id = id;
		}
		else
			Insert(g, id, i + 1, tn);
	}
	public:void insert(std::string g, T id)
	{
		m->ct++;
		Insert(g, id, 0, m);
	}
	private:T Search(std::string &g, int i, trie_node<T>* M)
	{
		if (m == NULL)return (T)0;
		trie_node<T> * tn = M->search(g[i]);
		if (tn == NULL)
			return (T)0;
		if (i == g.size() - 1)
			return	tn->id;
		return Search(g, i + 1, tn);
	}
	public:T search(std::string g)
	{
		return Search(g, 0, m);
	}
	private:void Remove(std::string &g, int i, trie_node<T>* M)
	{
		if (m == NULL)return;
		trie_node <T>* tn = M->search(g[i]);
		if (tn == NULL || i >= g.size())
			return;
		tn->ct--;
		Remove(g, i + 1, tn);
		if (tn->ct == 0)
		{
			M->remove(g[i]);
		}
	}
	public:void remove(std::string g)
	{
		Remove(g, 0, m);
	}
	private:void removeall(trie_node<T> *m)
	{
		if (m == NULL)return;
		for(int i = 0;i<m->M.size();i++)
			removeall(m->M[i].second);
		delete m;
	}
	private:void Peek(trie_node<T>* m, std::vector<T>&V)
	{
		if (m == NULL)return;
		V.push_back(m->id);
		for (int i = 0; i<m->M.size(); i++)
			Peek(m->M[i].second,V);
	}
	public: std::vector<T> peek(std::string g)
	{
		std::vector<T>V;
		trie_node <T> *M;
		M = m;
		for (int i = 0; i<g.size()&& M!=NULL; i++)
		{
			M = M->search(g[i]);
		}
		Peek( M, V);
		return V;
	}
	public:~trie()
	{
		removeall(m);
	}
};
#endif

