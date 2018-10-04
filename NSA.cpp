#include<bits/stdc++.h>
using namespace std;
long long main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		long long arr1[s.length()][26];
		long long arr2[s.length()][26];

		for(long long i=0;i<s.length();i++)
		{
			for(long long j=0;j<26;j++)
			{
				if(i==0)
				{
					arr1[i][j]=0;
				}
				else
				{
					if(j>(s[i-1]-'a'))
					{
                                                                arr1[i][j]=arr1[i-1][j]+1;
					}	
					else
					{
                                                                arr1[i][j]=arr1[i-1][j];
					}
				}
			}
		}
		
	            


		for(long long i=s.length()-1;i>=0;i--)
		{
			for(long long j=0;j<26;j++)
			{
				if(i==s.length()-1)
					arr2[i][j]=0;
				else
				{
					if(j<(s[i+1]-'a'))
					{
						arr2[i][j]=arr2[i+1][j]+1;
					}
					else
					{
						arr2[i][j]=arr2[i+1][j];
					}
				}
			}
		}


		 count=0;

		for(long long i=0;i<s.length();i++)
		{
			count+=(arr1[i][s[i]-'a']);
		}
		
	  // cout<<count<<endl;
     
       long long ans=count;

		for(long long i=0;i<s.length();i++)
		{
			long long y=(count-(arr1[i][s[i]-'a'])-arr2[i][s[i]-'a']);
			
			for(long long j=0;j<26;j++)
			{
                  long long x=(abs(j-(s[i]-'a')));

                  long long w=y+arr1[i][j]+arr2[i][j];

                  ans=min(ans,x+w);
			}
		}

		cout<<ans<<endl;
	}
	return 0;
}