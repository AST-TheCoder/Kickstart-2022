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

ll n;
string s,x;

ll solve(ll i){

    //cout<<i<<" "<<x<<endl;
    if(i==n){
        string temp="#";
        for(ll i=0;i<n;i++){
            temp+=x[i];
            temp+='#';
        }
        //cout<<temp<<endl;
        for(ll i=5;i<(ll)temp.size()-5;i++){
            if(temp[i-1]==temp[i+1] && temp[i-2]==temp[i+2] && temp[i-3]==temp[i+3] && temp[i-4]==temp[i+4] && temp[i-5]==temp[i+5]) return 0;
        }
        for(ll i=0;i<n;i++){
            if(x[i]!=s[i] && s[i]!='?') return 0;
        }
        return 1;
    }

    ll p=0;
    for(ll j=i-3,k=0;j+k<i && i>=4;k++){
        if(x[j+k]!=x[i-k-1]) p=1;
        //cout<<x[j+k]<<" "<<x[i-k-1]<<" "<<j+k<<" "<<i-k-1<<endl;
    }
    ll q=0;
    for(ll j=i-4,k=0;j+k<i && i>=5;k++){
        if(x[j+k]!=x[i-k-1]) q=1;
    }
    //cout<<p<<" "<<q<<endl;

    if(i<4){
        if(s[i]=='?'){
            x[i]='0';
            ll chk=solve(i+1);
            if(chk) return 1;
            x[i]='1';
            chk=solve(i+1);
            if(chk) return 1;
        }
        else{
            x[i]=s[i];
            ll chk=solve(i+1);
            if(chk) return 1;
        }
    }
    else if(!p && !q && i>4) return 0;
    else if(i>=4 && !p){
        if(x[i-4]=='0') x[i]='1';
        else x[i]='0';
        if(x[i]!=s[i] && s[i]!='?') return 0;
        ll chk=solve(i+1);
        if(chk) return 1;
    }
    else if(i>=5 && !q){
        if(x[i-5]=='0') x[i]='1';
        else x[i]='0';
        if(x[i]!=s[i] && s[i]!='?') return 0;
        ll chk=solve(i+1);
        if(chk) return 1;
    }
    else if(x[i-1]==x[i-2] && i<n-2){
        if(x[i-2]=='0') x[i]='1';
        else x[i]='0';
        if(x[i]!=s[i] && s[i]!='?') return 0;
        ll chk=solve(i+1);
        if(chk) return 1;
    }
    else{
        if(s[i]=='?'){
            x[i]='0';
            ll chk=solve(i+1);
            if(chk) return 1;
            x[i]='1';
            chk=solve(i+1);
            if(chk) return 1;
        }
        else{
            x[i]=s[i];
            ll chk=solve(i+1);
            if(chk) return 1;
        }
    }
    x[i]='-';
    return 0;
}

int main()
{   
    
    ll t,ii=0;
    cin>>t;

    while(t--){
        cin>>n>>s;
        x.clear();
        for(ll i=0;i<n;i++) x+='-';
        
        ll chk=solve(0);
        cout<<"Case #"<<++ii<<": ";
        if(chk) cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
