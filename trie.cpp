#include<bits/stdc++.h>
#define UMAP unordered_map<char,trie_node *,hasher,equalr>
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
class trie_node
{
    public :
    UMAP M;
    int id;
    int ct;
    trie_node(int i)
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
class trie
{
    private:trie_node * m;
    public:trie()
    {
        m = new trie_node();
    }
    private:void Insert(string &g,int id,int i,UMAP &M)
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
                M[g[i]] = new trie_node(id);
            return;
        }
        if(M.find(g[i]) == M.end())
            M[g[i]] = new trie_node();
        M[g[i]]->ct++;
        Insert(g,id,i+1,M[g[i]]->M);
    }
    public:void insert(string g,int id)
    {
        Insert(g,id,0,m->M);
    }
    private:int Search(string &g,int i,UMAP &M)
    {
        if(M.find(g[i]) == M.end())
            return -1;
        if(i == g.size()-1)
            return M[g[i]]->id;
        return Search(g,i+1,M[g[i]]->M);
    }
    public:int search(string g)
    {
        return Search(g,0,m->M);
    }
    private:void Remove(string &g,int i,UMAP &M)
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
    private :void removeall(trie_node *m)
    {
        if(m==NULL)return;
        UMAP ::iterator it;
        for(it = m->M.begin();it!=m->M.end();it++)
        {
            removeall((*it).second);
        }
        delete m;
    }
    public:~trie()
    {
        cout<<"1";
        removeall(m);
        cout<<"2";
    }
};
void simulate()
{
    trie t;
    for (int k = 0;k<1;k++)
    {
        for(int i = 0;i<100000;i++)
        {
            t.insert(toString(i),i);
        }
        for(int i = 0;i<100000;i++)
        {
            t.remove(toString(i));
        }
    }
}
void saveTrie(string place,trie &t)
{

}
trie loadTrie(string place)
{
    trie t;
    return t;
}
int main()
{
    simulate();
    return 0;
}

