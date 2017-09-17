#include "trie.cpp"
using namespace std;
template <typename T>string toString(T a)
{
    stringstream ss;
    ss<<a;
    string g;
    ss>>g;
    return g;
}
void simulate()
{
    trie<double> t;
    int o;
    for (int k = 0;k<1;k++)
    {
        for(int i = 0;i<4000000;i++)
        {
            t.insert(toString(i),i);
        }
        //cout<<k<<"\n";
        //cin>>o;
        for(int i = 0;i<4000000;i++)
        {
            t.remove(toString(i));
        }
        //cout<<k<<"\n";
        //cin>>o;
    }
}
int main()
{
    int t;
    cin>>t;
    simulate();
    cout<<"okay\n";
    cin>>t;
    return 0;
}
