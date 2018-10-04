#include<bits/stdc++.h>
using namespace std;

string fun(int i,int j,string s)
{
	char c=s[i];
	s.erase(i,1);
	s.insert(s.begin()+j,1,c);
    
    return s;

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		string mi=s;
		string p;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
                 string ans=fun(i,j,s);
                 mi=min(mi,ans);
			}
		}

		cout<<mi<<endl;
	}
	return 0;
}