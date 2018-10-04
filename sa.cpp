#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ll n,m,x;
   cin>>n>>m>>x;

   vector< ll > s;
   vector< ll > t;
   ll val;



   for(ll i=0;i<n;i++)
   {  
       cin>>val;
       s.push_back(val);
   }

   for(ll j=0;j<n;j++)
   {
      cin>>val;
      t.push_back(val);
   }

   sort(s.begin(),s.end());
   sort(t.begin(),t.end());

  long long temp= (s[s.size()-1]-s[0]+t[t.size()-1]-t[0]);

  while(1)
  {
       s[s.size()-1]-=x;
       t[t.size()-1]-=x;

       sort(s.begin(),s.end());
       sort(t.begin(),t.end());

       if(temp>=(s[s.size()-1]-s[0]+t[t.size()-1]-t[0]))
       {
         temp=(s[s.size()-1]-s[0]+t[t.size()-1]-t[0]);
       }
       else
       {
        break;
       }
  }

  cout<<temp<<endl;
}
