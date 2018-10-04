//Author: Jaydeep
//
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define vec vector<ll>
#define matrix vector<vector<ll> >
#define pritnf printf

template <typename T>
string NumberToString ( T Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

ll StringToNumber (string str)
{
	stringstream sstr(str);
	ll val;
	sstr >> val;
	return val;
}


int main()
{

    ll p=45676279578789;

    string s=NumberToString(p);

    cout << s << "\n";

    ll q=StringToNumber(s);

    cout << q << "\n";

    return 0;
}
