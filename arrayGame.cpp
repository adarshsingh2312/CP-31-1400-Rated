//Jai shree ram
// Will grind till end...
// 1904C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pair<int,int>>

void solve(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(k>=3){
        cout<<0<<endl;
        return;
    }
    vll diff;
    ll mini = LLONG_MAX;
    for(ll i=0; i<n; i++){
        mini = min(mini,a[i]);
    }
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            ll d = abs(a[i]-a[j]);
            diff.push_back(d);
        }
    }
    for(ll i=0; i<diff.size(); i++){
        mini = min(diff[i],mini);
    }
    sort(diff.begin(),diff.end());
    if(k==1){
        cout<<mini<<endl;
        return;
    }
    for(ll i=0; i<diff.size(); i++){
        ll idx = lower_bound(a.begin(),a.end(),diff[i])-a.begin();
        if(idx==0){
            mini = min(mini,abs(diff[i]-a[idx]));
        }
        if(idx>0 && idx<n){
            mini = min(mini,abs(diff[i]-a[idx]));
            mini = min(mini,abs(diff[i]-a[idx-1]));
        }
    }
    cout<<mini<<endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}