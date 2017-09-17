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
        for(int i = 0;i<10000;i++)
        {
            t.insert(toString(i),i);
        }
        double d;
        cout<<"enter"<<endl;
        cin>>d;
        vector<double> V;
        V = t.peek(toString(d));
        for(int i = 0;i<V.size();i++)
        {
            cout<<V[i]<<"\n";
        }
    }
}
int main()
{
    simulate();
    cout<<"okay\n";
    return 0;
}
