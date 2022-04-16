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
        string s,p;
        cin>>s>>p;
        s+='#';

        ll ans=0;
        ll i,j;
        for(i=0,j=0;j<p.size();){
            if(s[i]==p[j]){
                i++,j++;
            }
            else{
                ans++;
                j++;
            }
        }
        cout<<"Case #"<<++ii<<": ";
        if(i+1==s.size()) cout<<ans<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
