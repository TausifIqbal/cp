#include <bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int, int> pii; 
#define ll long long
#define ld long double
#define ar array
const int mxN=1e4+4;
const int mod=1e9+7;
// const int mod=998244353;
const ll INF=4e18;
// const int INF= 1e9;
#define what_is(x) cerr << #x << " is " << x << endl;
using Matrix = vector<vector<long long>>;
using vll = vector<long long>;
using cd =complex<double>;
const double PI= acos(-1);
typedef pair<int,int> pi;
clock_t begtime = clock();
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif
#define timetaken() cout << "\n\nTime elapsed: " << (float)(clock() - begtime)/1000.0
 
 
void add(int &a, int b){
    a=a+b;
    if(a>mod){
        a-=mod;
    }
}
// code starts from here 



void solve(){    
    int n,m;
    cin>>n>>m;
    vector<array<int,2>> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        int c ; cin>>c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }


    vector<vector<int>> dp(n+1,vector<int> (n+1,INF));

    dp[0][1]=0;
    // dp(h, i)  , cost of being at ith city with h hop
    for(int hop=1;hop<=n;hop++){
        for(int v=1;v<=n;v++){
            for(auto[u,c]: adj[v]){
                dp[hop][v]=min(dp[hop][v],hop*c + dp[hop-1][u]);
            }
            
        }
    }

    for(int i=1;i<=n;i++){
        int ans=INF;
        for(int j=0;j<=n;j++){
            ans=min(ans,dp[j][i]);
        }
        if(ans==INF){
            cout<<"-1"<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    //https://my.newtonschool.co/playground/code/sph3bliiktwi/
}   
// edge case n=1       
signed main() {
// int main(){
    // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);              
        // freopen("output.txt","w",stdout);
    // #endif  
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // fflush(stdout);
    // cout<<setprecision(10)<<fixed;
    // timetaken();
   
    int t=1;
    // cin>>t;
    
    while(t--){
       // cout<<"Case #"<<i<<": ";
        solve();
      //  cout<<endl;
      //  i++;
    }
    return 0;
   
}
