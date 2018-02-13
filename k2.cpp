#include "osf.cpp"
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#define ll long long;
using namespace std;

vector<string> documents;

map<string,vector<unsigned int> > words;

void filePrint(std::string& str)
{
    documents.push_back(str);
    int docnum = documents.size()-1;
	std::ifstream fs(str.c_str());
	if(!fs.is_open())
		return ;
	std::cout<<"-----parsing file:"<<str<<"\n";
	set<string>SETT;
	while(!fs.eof())
	{
		std::string g;
		getline(fs,g);
        replaceString(g,"",' ');
		stringstream ss ;
		ss << g;
		while(!ss.eof()){
            ss>>g;
            g = StemEnglish(g);
            SETT.insert(g);
		}
	}
	for(set<string>::iterator it = SETT.begin();it != SETT.end();it++)
    {
        words[(*it)].push_back(docnum);
    }
	std::cout<<"-----file done:"<<str<<"\n";
	fs.close();
}
vector<unsigned int> intersection(vector<unsigned int>&a , vector<unsigned int>&b )
{
    vector<unsigned int>c;
    for(int i=0,j=0; i<a.size()||j<b.size();)
    {
        if(a[i]==b[j])
        {
            c.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i]>b[j])
            j++;
        else
            i++;
    }
    return c;
}
vector<string> mergevecs(string g)
{
   set<string>SETT;
   replaceString(g,"",' ');
   stringstream ss ;
   ss << g;
   while(!ss.eof())
   {
        ss>>g;
        g = StemEnglish(g);
        SETT.insert(g);
    }
    vector<unsigned int>ans;
    bool f = 1;
    for(set<string>::iterator it = SETT.begin();it != SETT.end();it++)
    {
        if(f)
            ans = words[(*it)];
        else
            ans=intersection(ans,words[(*it)]);
        f = 0;
    }
    vector<string>ANS;
    for(int i = 0;i<ans.size();i++)
    {
        ANS.push_back(documents[ans[i]);
    }
    return ANS;
}
int main()
{
	/*string str;
	str = "/gitrepo";
	//listAllFiles(str,filePrint);
	string g = "my*name$%^&is<>?,./gaurav";
	replaceString(g,"!@#$%^&*()_+-={}|[]\\:\"';:<>?,./",'_');
	cout<<"\n\n"<<g<<"\n\n";
	string a1 = "demonetization";
	string a2 = "relaxing";
	string a3 = "king";
	cout<<StemEnglish(a1)<<"\n";
	cout<<StemEnglish(a2)<<"\n";
	cout<<StemEnglish(a3)<<"\n";
	*/

	return 0;
}
