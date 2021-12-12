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

int intersection(string s1,string s2) //Naive intersection algo
{
    int ans = 0;
    for(int i=0;i<s1.size();i++)
    {
        ans += ((s1[i]=='1')&&(s2[i]=='1'));
    }
    return ans;
}


int solve(vector<string> &inp)
{
    int N = inp.size();
    bitset<365> sch[N];
    for(int i=0;i<N;i++)
    {
        sch[i] = bitset<365>(inp[i]);
    }
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            ans = max(ans,(int)(sch[i]&sch[j]).count());
            // ans = max(ans,intersection(inp[i],inp[j])); //Naive
        }
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int t;cin >> t;while(t--)
    vector<string> inp;
    int N,D;
    cin >> N >> D;
    for(int i=0;i<N;i++)
    {
        string s;
        cin >> s;
        inp.pb(s);
    }
    cout << solve(inp);

    return 0;
}