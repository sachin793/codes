#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	  string s;
   	  cin>>s;
   	  int has[26]={0};
   	  int arr[s.length()]={0};
   	  vector< int > v[26];
      int count=0;
   	  for(int i=0;i<s.length();i++)
   	  {
   	  	if(has[s[i]-'a']==0)
   	  		count++;
   	  	arr[i]=count;
   	  	has[s[i]-'a']++;
   	  
        
   	  } 
   	  
     for(int i=0;i<s.length();i++)
     {
     	cout<<arr[i]<<endl;
     }
      int ans=0;
      v[s[0]-'a'].push_back(0);
   	  for(int i=1;i<s.length();i++)
   	  {
         for(int j=0;j<v[s[i]-'a'].size();j++)
         {
                if(arr[i-1]-arr[v[i][j]]<=1)
                {
                	ans++;
                }
         }
         v[s[i]-'a'].push_back(i);
   	  }

   	  cout<<ans<<endl;
   }
   return 0;
}
