#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
    int sum=0;
  
    int  k;
    cin>>k;
    
    int arr[27];
    arr[0]=0;
    for(int i=1;i<=26;i++)
    {
    	cin>>arr[i];
    }

    for(int i=0;i<s.length();i++)
    {
    	sum+=((i+1)*arr[s[i]-'a'+1]);
    }
 
    
    sort(arr,arr+27);
    
     for(int i=s.length()+1;(unsigned)i<(s.length()+k+1);i++)
     {
     	sum+=(i*arr[26]);
     }
     cout<<sum<<endl;
     return 0;
}
