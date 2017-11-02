#include <bits/stdc++.h>
struct SET
{
	SET * root;
	long long rank;
};
class cluster
{
	public:
	std::vector < SET * >V;
	cluster(long long n)
	{
		V.clear();
		V.resize(n);
		for(long long i = 0;i<n;i++)
        {
            V[i] = new SET();
            V[i]->root = V[i];
            V[i]->rank = 1;
        }
			
	}
    ~cluster()
    {
        for(long long i = 0;i<V.size();i++)
        {
            delete V[i];
        }
        V.clear();
    }
	SET * find(long long index)
	{
		SET* s = V[index];
		std::vector<SET* >st;
		while(s != s->root)
		{
			st.push_back(s);
			s = s->root;
		}
		for(long long i = 0;i<st.size();i++)
		{
			st[i]->root = s;
			(s->rank)++;
		}
		return s;
	}
	void merge(long long a,long long b)
	{
		SET * s1 = V[a]->root;
		SET * s2 = V[b]->root;
		if(s1->rank > s2->rank)
		{
			s2->root = s1->root;
			s1->rank += s2->rank;
		}
		else
		{
			s1->root = s2->root;
			s2->rank += s1->rank;
		}
	}
};

using namespace std;
bool sorter(pair<int,pair<int,int> >a,pair<int,pair<int,int> >b)
{
    
    if(a.first == b.first)
        return a.second.first + a.second.second < b.second.first + b.second.second;
    return a.first < b.first;
}
int main()
{
	//kruskal's algorithm
	int n,m;
    cin>>n>>m;
    cluster c(n);
    vector<pair<int,pair<int,int> > >E(m);
    for(int i= 0;i<m;i++)
    {
        int x,y,r;
        cin>>x>>y>>r;
        x--;y--;
        E[i] = make_pair(r,make_pair(x,y));
    }
    sort(E.begin(),E.end(),sorter);
    int ans=0;
    for(int i = 0;i<E.size();i++)
    {
        int x,y,r;
        r = E[i].first;
        x = E[i].second.first;
        y = E[i].second.second;
        if(c.find(x) != c.find(y))
        {
            c.merge(x,y);
            ans+=r;
        }
    }
    cout<<ans;
	return 0;
}
