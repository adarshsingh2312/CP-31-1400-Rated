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

bool valid(int l, int r, int k, vector<vi> &v){
    int range = r-l+1;
    int res = 0;
    for(int i=0; i<=30; i++){
        if(v[r][i] - v[l-1][i] == range) res |= (1<<i);
    }
    return res >= k;
}

void solve(){
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    vector<vi> v(n+1,vi(31,0));
    int q;
    cin>>q;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=30; j++){
            int set = ((1<<j) & a[i]);
            v[i][j] = v[i-1][j] + (set==0 ? 0 : 1);
        }
    }
    while(q--){
        int l,k;
        cin>>l>>k;
        if(a[l]<k){
            cout<<-1<<" ";
            continue;
        }
        int lo = l;
        int hi = n;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(valid(l,mid,k,v)){
                lo = mid;
            }
            else{
                hi = mid-1;
            }
        }
        if(valid(l,hi,k,v)){
            cout<<hi<<" ";
        }
        else if(valid(l,lo,k,v)){
            cout<<lo<<" ";
        }
        else{
            cout<<-1<<" ";
        }
    }
    cout<<endl;
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