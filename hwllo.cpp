#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
int main()
{
	string s;
	cin>>s;
	int flag=0;
	if(s.length()==1)
	{
		flag=1;
	}
	else
	if(s.length()==3)
	{
         if(!(s[0]==s[1]==s[2])&&(s[0]==s[1])||(s[0]==s[2])||(s[2]==s[1]))
         	{
         		 flag=1;
			}	
	
	
	}
	else
	{
         int p1=0;
         int p2=0;
         for(int i=1;i<s.length()-1;i++)
         {
         	if(s[i]!=s[i-1])
         	{
         		p1=1;
         	}
         }

       for(int i=2;i<s.length();i++)
       {
       	if(s[i]!=s[i-1])
       	{
       		p2=1;
       	}
       }

       printf("%c %c\n",s[0],s[s.length()-1] );
       if((p1==0||p2==0)&&(s[0]!=s[s.length()-1]))
       {
           flag=1;
       }
	}

	if(flag==0)
	{
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;
	return 0;
}