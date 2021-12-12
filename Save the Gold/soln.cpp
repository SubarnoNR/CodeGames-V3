#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int max_seq=0;
	set<int> s;

	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		s.insert(x);
        if(x>max_seq)max_seq=x;
	}
	vector<int>v;
	for(auto it=s.begin(); it!=s.end(); it++){
		v.push_back((*it));
	}

	int maxinarr[2*max_seq+1];
	int curr=0;
	int m=v.size();
	for(int i=0;i<=2*max_seq;i++){
		if(curr==m){maxinarr[i]=m-1;continue;}
		while(v[curr]<i){curr++;if(curr==m)break;}
		maxinarr[i]=curr-1;
	}

    int maxi=0;
	for(int i=m-1; i>=0; i--){
		int val=v[i];
		if(val<=maxi){
			break;
		}
		for(int j=2; j*val<=2*max_seq; j++){
			int it=maxinarr[j*val];
			int num=v[it];
			if(num<val){
				continue;
			}
			maxi=max(maxi, num%val);	
		}
	}
	cout<<maxi*1000<<endl;
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
