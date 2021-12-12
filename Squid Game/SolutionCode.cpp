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
int grundy(int n,int k)
{
    while(n%k!=0)
    {
        int d = n/k;
        if((n%k)%(d+1)==0)
        {
            n = d*k;
        }
        else
        {
            n -= ((int)ceil(double(n%k)/double(d+1)))*(d+1);
        }
    }
    return n/k;
}


void solve()
{
    int n;
    cin >> n;
    int a,k;
    vector<int> g;
    for(int i=0;i<n;i++)
    {
        cin >> a >> k;
        g.pb(grundy(a,k));
    }
    int x = g[0];
    for(int i=1;i<n;i++)
    {
        x^=g[i];
    }
    cout << ((x==0)?"SECOND":"FIRST");
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int t;cin >> t;while(t--)
    solve();

    return 0;
}