#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){cin >> arr[i];}
    int dp[n][n];
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(j==i){ 
				dp[i][j] = arr[i];
                continue;
			}
            else{
                dp[i][j] = max(arr[i] - dp[i+1][j],arr[j]-dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n-1] << "\n";
}


signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}
