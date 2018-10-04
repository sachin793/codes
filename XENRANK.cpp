#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];

		for(int i=0;i<m;i++)
			cin>>arr[i];

		int count=0;

		unordered_map< int , int > mp;

		for(int i=0;i<m;i++)
		{
			if(mp[arr[i]]==0 )
			{
                 if(count<n)
                 {
                     count++;
                     mp[arr[i]]=count;
                 } 
                 else
                 {
                     count++;
                     for(int j=0;j<m;j++)
                     {
                     	if(arr[j]!=arr[i] && mp[arr[j]]!=0)
                     	{
                     		mp[arr[i]]=mp[arr[j]];
                     		mp[arr[j]]=0;
                     	}
                     }
                 }
			}
		}

		cout<<count<<endl;
	}
	return 0;
}