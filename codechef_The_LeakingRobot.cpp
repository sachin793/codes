#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		int flag=0;
		if(a==0 && b==0)
		{
			flag=1;
			cout<<"YES"<<endl;
		}
		
		if(a>0 && a%2==1)
		{
            if(b>=(-(a-1)) && b<=(a+1))
            {
                	flag=1;
                	cout<<"YES"<<endl;
            }
	    }
			
				
		if(a<0 && (-a)%2==0)
		{
            if(b>=(a) && b<=(-a))
            {
                  flag=1;
                  cout<<"YES"<<end;
            }
                        
		}

		if(b>0 && b%2==0)
		{
             if(a>=(-b) && a<=(b-1))
             {
             	flag=1;
             	cout<<"YES"<<endl;
             }
		}

		if(b<0 && (-b)%2==0)
		{
			if(a>=b && a<=(-(b-1)))
			{
				flag=1;
				cout<<"YES"<<endl;
			}
		}

		if(flag==0)
			cout<<"NO"<<endl;
	}
	return 0;
}