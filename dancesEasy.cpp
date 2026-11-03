//Jai shree ram
// Will grind till end...
// 1883/G1
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
bool all(vi &b, vi &c){
    for(int i=0; i<b.size(); i++){
        if(c[i]>=b[i])   return false;
    }
    return true;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n-1);
    vi b(n);
    for(int i=0; i<n-1; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    vi c(n);
    c[0] = 1;
    for(int i=1; i<n; i++){
        c[i] = a[i-1];
    }
    sort(c.begin(),c.end());
    sort(b.begin(),b.end());
    int j = 0;
    int ans = 0;
    if(all(b,c)){
        cout<<0<<endl;
        return;
    }
    for(int i=0; i<n; i++){
        int idx = upper_bound(b.begin()+j+1,b.end(),c[i])-b.begin();
        j = idx;
        if(j==n){
            ans = n-i;
            break;
        }
        // cout<<j<<" ";
    }
    cout<<ans<<endl;
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