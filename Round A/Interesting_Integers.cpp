#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

string a,b;
ll dp[14][110][2][2][7][5][3][3][2][2],sz;

ll solve(ll id,ll sum,ll x,ll y,ll p,ll q,ll r,ll s,ll chk1,ll chk2){

    if(id==a.size()){
        //cout<<id<<" "<<sum<<" "<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
        if(!chk1 && !sum && !p && !q && !r && !s) return 1;
        else if(chk1 && chk2 && !sum) return 1;
        else return 0;
    }
    
    if(dp[id][sum][x][y][p][q][r][s][chk1][chk2]!=-1) return dp[id][sum][x][y][p][q][r][s][chk1][chk2];
    dp[id][sum][x][y][p][q][r][s][chk1][chk2]=0;
    ll l,u;
    if(x) l=0;
    else l=(a[id]-'0');
    if(y) u=9;
    else u=(b[id]-'0');
    for(ll i=l;i<=u;i++){
        if(i>sum) continue;
        ll s1=x,s2=y;
        if(i!=l) s1=1;
        if(i!=u) s2=1;
        if(i==0 && (id>=sz || s1)){
            dp[id][sum][x][y][p][q][r][s][chk1][chk2]+=solve(id+1,sum-i,s1,s2,0,0,0,0,chk1,1);
            continue;
        }
        ll a=p,b=q,c=r,d=s;
        if(i==2) a=max(0LL,p-1);
        if(i==3) b=max(0LL,q-1);
        if(i==4) a=max(0LL,p-2);
        if(i==5) c=max(0LL,r-1);
        if(i==6) a=max(0LL,p-1),b=max(0LL,q-1);
        if(i==7) d=max(0LL,s-1);
        if(i==8) a=max(0LL,p-3);
        if(i==9) b=max(0LL,q-2);
        dp[id][sum][x][y][p][q][r][s][chk1][chk2]+=solve(id+1,sum-i,s1,s2,a,b,c,d,chk1,chk2);
    }
    return dp[id][sum][x][y][p][q][r][s][chk1][chk2];
}

int main()
{   
    
    ll t,ii=0;
    cin>>t;

    while(t--){
        cin>>a>>b;
        string x;
        sz=0;
        while(x.size()+a.size()<b.size()) x+='0',sz++;
        a=x+a;
        ll ans=0;
        memset(dp,-1,sizeof(dp));
        for(ll i=1;i<=108;i++){
            ll p=0,q=0,r=0,s=0,sum=i;
            while(sum%2==0){
                sum/=2;
                p++;
            }
            while(sum%3==0){
                sum/=3;
                q++;
            }
            while(sum%5==0){
                sum/=5;
                r++;
            }
            while(sum%7==0){
                sum/=7;
                s++;
            }
            if(sum!=1) ans+=solve(0,i,0,0,0,0,0,0,1,0);
            else ans+=solve(0,i,0,0,p,q,r,s,0,0);
        }
        cout<<"Case #"<<++ii<<": "<<ans<<endl;
    }

    return 0;
}
