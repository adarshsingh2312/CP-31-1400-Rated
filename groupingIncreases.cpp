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
void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int x = n+1;
    int y = n+1;
    int p = 0;
    for(int i=0; i<n; i++){
        if(x>y) swap(x,y);
        if(a[i]>x){
            if(a[i]>y){
                p++;
                x = a[i];
            }
            else{
                y = a[i];
            }
        }
        else{
            x = a[i];
        }
    }
    cout<<p<<endl;
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