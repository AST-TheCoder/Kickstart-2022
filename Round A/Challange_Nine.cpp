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

int main()
{   
    
    ll t,ii=0;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        ll sum=0;
        for(ll i=0;i<s.size();i++){
            sum+=(s[i]-'0');
        }

        ll ans=9-(sum%9);
        if(ans==9) ans=0;
        ll ok=0;
        cout<<"Case #"<<++ii<<": ";
        for(ll i=0;i<s.size();i++){
            if(i==0 && ans==0){
                cout<<s[i];
                continue;
            }
            if(s[i]>(char)(ans+'0')){
                cout<<ans;
                ok=1;
                ans=9;
            }
            cout<<s[i];
        }
        if(!ok) cout<<ans;
        cout<<endl;
    }

    return 0;
}
