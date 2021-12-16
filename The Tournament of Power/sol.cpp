// Credits to Karthikeya Namoju, CSE Sophomore

#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define T third
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<pair<int, int>> vp;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
const int C1 = 1e9 + 7;
const int C2 = 998244353;
//const int inf=1e18;
void yes()
{
    cout << "YES\n";
}
void no()
{
    cout << "NO\n";
}
int binpow(int a, int b, int m = C1)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v)
{
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v])
    {
        if (mt[to] == -1 || try_kuhn(mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }
    return false;
}
int f()
{
    mt.assign(k, -1);
    for (int v = 0; v < n; ++v)
    {
        used.assign(n, false);
        try_kuhn(v);
    }
    mt.assign(k, -1);
    vector<bool> used1(n, false);
    for (int v = 0; v < n; ++v)
    {
        for (int to : g[v])
        {
            if (mt[to] == -1)
            {
                mt[to] = v;
                used1[v] = true;
                break;
            }
        }
    }
    int res{};
    for (int v = 0; v < n; ++v)
    {
        if (used1[v])
            continue;
        used.assign(n, false);
        try_kuhn(v);
    }
    for (int i = 0; i < k; ++i)
        if (mt[i] != -1)
            res++;

    return res;
}
//Variables*******************************************
void solve()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vi l1(x), l2(y);
    map<int, int> m1, m2;
    for (int i = 0; i < x; i++)
    {
        cin >> l1[i];
        m1[l1[i]] = -1;
    }
    for (int i = 0; i < y; i++)
    {
        cin >> l2[i];
        m2[l2[i]] = -1;
    }
    vi lik(a), unl(b);
    map<int, int> sel;
    for (int i = 0; i < a; i++)
    {
        cin >> lik[i];
        sel[lik[i]] = 1;
    }
    for (int i = 0; i < b; i++)
    {
        cin >> unl[i];
        sel[unl[i]] = -1;
    }
    map<pair<int, int>, int> graph;
    int cnt1 = 0, cnt2 = 0;
    vp v;
    for (int i = 0; i < c; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        v.pb(mp(x1, x2));
        // int len1 = s.size();
        //cout<<len1<<endl;
        if (sel[x1] == -1)
        {
            sel[x2] = 1;
        }
        if (sel[x2] == -1)
        {
            sel[x1] = 1;
        }
        //cout<<len2<<endl;
        //graph[mp(m1[x1], m2[x2])] = 1;
    }
    vp v2;
    for (int i = 0; i < c; i++)
    {
        // cout<<v[i].F<<" "<<v[i].S<<endl;
        if (sel[v[i].F] == 0 && sel[v[i].S] == 0)
            v2.pb(v[i]);
    }
    //cout<<v2.size()<<endl;
    for (auto p : v2)
    {
        int x1 = p.F, x2 = p.S;
        if (m1[x1] == -1)
        {
            m1[x1] = cnt1;
            cnt1++;
        }
        if (m2[x2] == -1)
        {
            m2[x2] = cnt2;
            cnt2++;
        }
        //cout<<m1[x1]<<" "<<m2[x2]<<endl;
    }
    g.resize(cnt1);
    for (auto p : v2)
    {
        int x1 = p.F, x2 = p.S;
        g[m1[x1]].pb(m2[x2]);
        //cout<<m1[x1]<<" "<<m2[x2]<<endl;
    }
    int ans{};
    for (auto p : sel)
    {
        if (p.S == 1)
            ans++;
    }
    n = cnt1;
    k = cnt2;
    //cout<<ans<<endl;
    //cout<<n<<" "<<k<<endl;
    ans += f();
    cout << ans << endl;
}
//*****************************************************

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
