#include<bits/stdc++.h>
using namespace std;
long long MOD=10e9+7;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		long long ans=1;
		long long sum=0;
		for(int i=0;i<s.length();i++)
		{
			if(i%2==0)
			{
				  if(s[i]=='l')
				  {
                      ans=((ans%MOD)*(2%MOD))%MOD;
                    
				  }
				  else
				  {
                      ans=((((ans%MOD)*(2%MOD)%MOD))+(2%MOD))%MOD;
                    
				  }

			}
			else
			{
                        if(s[i]=='l')
                        {
                             ans=((((ans%MOD)*(2%MOD))%MOD)-(1%MOD))%MOD;
                             
                        }
                        else
                        {
                             ans=(((ans%MOD)*(2%MOD))%MOD+(1%MOD))%MOD;
                             
                        }
			}
		}

		cout<<ans%MOD<<endl;
	}
	return 0;
}
