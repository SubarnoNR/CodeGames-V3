#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define int long long
int PRIME = 1000000007;
#define ff first
#define ss second
#define pb push_back
#define makep make_pair
#define inf (int)(10e17)
#define ninf (int)(-10e17)

//Global Variables ---------

//Functions -----------
int mod(int x)
{
	while(x<0)
	{
		x += 26;
	}
	return x%26;
}


void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int diff[n-1];
    for(int i=0;i<n-1;i++)
    {
    	diff[i] = (int)(s[i+1]-s[i]);
    }
    vector<int> checker;
    string w = "CHEDDAR";
    for(int i=0;i<w.size()-1;i++)
    {
    	checker.pb(w[i+1]-w[i]);
    }
    for(int i=0;i<s.size()-1;i++)
    {
    	int ind = i, curr = 0;
    	while((diff[ind]-checker[curr])%26==0)
    	{
    		ind++;
    		curr++;
    		if(curr==6)
    		{
    			break;
    		}
    	}
    	if(curr==6)
    	{
    		cout << mod(s[i]-'C');
    		return;
    	}
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}