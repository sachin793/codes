#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int max=-1;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
        int has[26]={0};
        for(int i=0;i<s.length();i++)
        {
        	has[s[i]-'a']++
        }
 
        int count=0;
        for(int i=0;i<26;i++)
        {
        	if(has[i]!=0)
        	{
        		count++;
        	}
        }

        if(count<=k && s.length()>max)
        {
        	max=s.length();
        }
	}
	cout<<max<<endl;
}