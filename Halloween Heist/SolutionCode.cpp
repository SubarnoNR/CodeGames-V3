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
string transform(string s)
{
	string ans = "";
	for(auto c : s)
	{
		if(c=='A')
		{
			ans += 'Z';
		}
		else
		{
			ans += (c-1);
		}
	}
	return ans;
}

void solve()
{
    int N;
    cin >> N;
    string s;
    cin >> s;
    for(int k=0;k<26;k++)
    {
    	if(s.find("CHEDDAR")!=string::npos)
    	{
    		cout << k;
    		return;
    	}
    	s = transform(s);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int t;cin >> t;while(t--)
    solve();
    // string ans = "";
    // ans += ('B'-1);
    // cout << ans << "\n";

    return 0;
}