#include<bits/stdc++.h>
uisng namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		string ans;
		int has[26]={0};
		for(int i=0;i<s.length();i++)
		{
			has[s[i]-'a']++
		}

         int count=0;
         int i=0;
         while(count<=s.length())
         {
             if(has[i]!=0)
             {
             	ans=ans+(char)(i+97);
             	has[i]-=1;
             }
            
            i++;
            if(i>25)
            {
            	i=0;
            }

         }

         if(ans[s.length()-1]==ans[s.length()-2])
         {
         	cout<<-1<<endl;
         }
         else
         {
         	cout<<ans<<endl;
         }
	}
	return 0;
}