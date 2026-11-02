//Jai shree ram
// Will grind till end...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pair<int,int>>
class Node{
    public:
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
bool possible(ll mid, vector<pll> &a){
    ll n = a.size();
    ll l = 0;
    ll r = 0;
    for(ll i=0; i<n; i++){
        ll L = l-mid;
        ll R = r+mid;
        l = max(L,a[i].first);
        r = min(R,a[i].second);
        if(l>r) return false;
    }
    return true;
}
void solve(){
    ll n;
    cin>>n;
    vector<pll>v(n);
    ll maxi = 0;
    for(ll i=0; i<n; i++){
        ll l,r;
        cin>>l>>r;
        v[i] = {l,r};
        maxi = max(r,maxi);
    }
    ll lo = 0;
    ll hi = maxi;
    while(hi-lo>1){
        ll mid = lo+(hi-lo)/2;
        if(possible(mid,v)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    if(possible(lo,v)){
        cout<<lo<<endl;
    }
    else{
        cout<<hi<<endl;
    }
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