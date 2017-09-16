#include<bits/stdc++.h>
//#define UMAP unordered_map<char,trie_node<T> *,hasher,equalr>
using namespace std;

/*
    Basic Functions to do shitt
*/
template <typename T>string toString(T a)
{
    stringstream ss;
    ss<<a;
    string g;
    ss>>g;
    return g;
}
void error(int id = -1,string g = "")
{
    g = "ERROR " + g;
    cout<<g<<" "<<id<<"\n";
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
    unordered_map<char,trie_node<T> *,hasher,equalr> M;
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
    private:void Insert(string &g,T id,int i,unordered_map<char,trie_node<T> *,hasher,equalr> &M)
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
    public:void insert(string g,T id)
    {
        Insert(g,id,0,m->M);
    }
    private:T Search(string &g,int i,unordered_map<char,trie_node<T> *,hasher,equalr> &M)
    {
        if(M.find(g[i]) == M.end())
            return (T)0;
        if(i == g.size()-1)
            return M[g[i]]->id;
        return Search(g,i+1,M[g[i]]->M);
    }
    public:T search(string g)
    {
        return Search(g,0,m->M);
    }
    private:void Remove(string &g,int i,unordered_map<char,trie_node<T> *,hasher,equalr> &M)
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
    public:void remove(string g)
    {
        Remove(g,0,m->M);
    }
    private :void removeall(trie_node<T> *m)
    {
        if(m==NULL)return;
        typename unordered_map<char,trie_node<T> *,hasher,equalr> ::iterator it;
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
void simulate()
{
    trie<int> t;
    int o;
    for (int k = 0;k<5;k++)
    {
        for(int i = 0;i<4000000;i++)
        {
            t.insert(toString(i),i);
        }
        cin>>o;
        for(int i = 0;i<5000000;i++)
        {
            t.remove(toString(i));
        }
        cout<<k<<"\n";
        cin>>o;
    }
}
int main()
{
    simulate();
    return 0;
}

