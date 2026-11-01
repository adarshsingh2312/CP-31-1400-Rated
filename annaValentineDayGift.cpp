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
ll trailing(ll n){
    ll num = n;
    ll cnt = 0;
    while(num!=0){
        ll d = num%10;
        if(d!=0)    break;
        cnt++;
        num/=10;
    }
    return cnt;
}
ll digits(ll n){
    ll num = n;
    ll cnt = 0;
    while(num!=0){
        cnt++;
        num/=10;
    }
    return cnt;
}
bool comp(const pll &a, const pll &b){
    return a.first > b.first;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vll a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    vector<pll> tz(n);
    vll d(n);
    for(ll i=0; i<n; i++){
        tz[i].first = trailing(a[i]);
        tz[i].second = digits(a[i]);
    }
    sort(tz.begin(),tz.end(),comp);
    ll cnt = 0;
    ll dig = 0;
    for(ll i=0; i<n; i++){
        if(cnt%2==0){
            dig+=(tz[i].second-tz[i].first);
        }
        else{
            dig += (tz[i].second);
        }
        cnt++;
    }
    if(dig>=(m+1)){
        cout<<"Sasha"<<endl;
    }
    else{
        cout<<"Anna"<<endl;
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