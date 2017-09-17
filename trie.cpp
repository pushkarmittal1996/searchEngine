#ifndef trie_cpp
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


void error(int id = -1,std::string g = "")
{
    if(id == -1)return;
    g = "ERROR " + g;
    std::cout<<g<<" "<<id<<"\n";
}
class hasher
{
    public:size_t operator()(char const &key)const
    {
        return (size_t)key;
    }
};
class equalr
{
    public: bool operator()(char const &k1,char const &k2)const
    {
        return k1 == k2;
    }
};



/*
    Trie Implememtation
*/
template<class T>class trie_node
{
    public :
    //unordered_map<char,trie_node<T> *,hasher,equalr> M;
    std::map<char,trie_node<T>* >M;
    T id;
    int ct;
    trie_node(T i)
    {
        id = i;
        ct = 1;
        M.clear();
    }
    trie_node()
    {
        M.clear();
        ct = 0;
        id = -1;
    }
};
template<class T>class trie
{
    private:trie_node<T> * m;
    public:trie()
    {
        m = new trie_node<T>();
    }
    private:void Insert(std::string &g,T id,int i,std::map<char,trie_node<T>* > &M)
    {
        if(i == g.size()-1)
        {
            if(M.find(g[i]) != M.end())
            {
                if(M[g[i]]->id != id&& M[g[i]]->id != -1)
                    error(-1,"Name Already used");
                else
                    M[g[i]]->id = id;
            }
            else
                M[g[i]] = new trie_node<T>(id);
            return;
        }
        if(M.find(g[i]) == M.end())
            M[g[i]] = new trie_node<T>();
        M[g[i]]->ct++;
        Insert(g,id,i+1,M[g[i]]->M);
    }
    public:void insert(std::string g,T id)
    {
        Insert(g,id,0,m->M);
    }
    private:T Search(std::string &g,int i,std::map<char,trie_node<T>* > &M)
    {
        if(M.find(g[i]) == M.end())
            return (T)0;
        if(i == g.size()-1)
            return M[g[i]]->id;
        return Search(g,i+1,M[g[i]]->M);
    }
    public:T search(std::string g)
    {
        return Search(g,0,m->M);
    }
    private:void Remove(std::string &g,int i,std::map<char,trie_node<T>* > &M)
    {
        if(M.find(g[i]) == M.end() || i>= g.size())
            return ;
        M[g[i]]->ct--;
        Remove(g,i+1,M[g[i]]->M);
        if(M[g[i]]->ct == 0)
        {
            delete M[g[i]];
            M.erase(g[i]);
        }
    }
    public:void remove(std::string g)
    {
        Remove(g,0,m->M);
    }
    private :void removeall(trie_node<T> *m)
    {
        if(m==NULL)return;
        typename std::map<char,trie_node<T>* > ::iterator it;
        for(it = m->M.begin();it!=m->M.end();it++)
        {
            removeall((*it).second);
        }
        delete m;
    }
    public:~trie()
    {
        removeall(m);
    }
};
#endif

