#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long tunel;
		cin>>tunel;
		long long tu[tunel];
		long double car1_end=0;
		long double car1_notend;
		for(long long i=0;i<tunel;i++)
		{
			cin>>tu[i];
			car1_end+=tu[i];
		}
          
          long long car,dis,spe;
          cin>>car>>dis>>spe;
          car1_end=(double)car1_end+((double)tunel-1)*((double)dis/spe);
          car1_notend=((double)car1_end - tu[tunel-1]);
          long double dif=0;
          long double car2_notend=(double)car1_notend+(double)tu[0];
          if(car1_end>car2_notend)
          {
               dif=((double)car1_end-(double)car2_notend);
          }

         long double ans=((double)(car-1)*tu[0]+car1_end+(car-1)*(double)dif)-(double)car1_end;
         printf("%.9Lf\n",ans);

	}
	return 0;
}
