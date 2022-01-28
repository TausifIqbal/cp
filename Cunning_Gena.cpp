#include <bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int, int> pii; 
#define ll long long
#define ld long double
#define ar array
const int mxN=1e6+4;
const int mod=1e9+7;
// const int mod=998244353;
const ll INF=4e18;
// const int INF= 1e10;
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

struct cmp{
    public:
        bool operator() (const array<ll,4>& a, const array<ll,4>& b){
            return a[1]<b[1];
        }
    }cmp;

void solve(){
    int n,m,b;
    cin>>n>>m>>b;

    vector<array<int,4>> f;
    for(int i=0;i<n;i++){
        int ci,ki,xi;
        cin>>ci>>ki>>xi;
        int pi=0;
        for(int j=0;j<xi;j++){
            int p; cin>>p;
            p--;
            pi|= (1<<p);
        }
        f.push_back({ci,ki,xi,pi});
    }
    sort(f.begin(),f.end(),cmp);

    vector<int> dp( ((1<<m)),INF );
    // use forward push dp
    // dp(mask)  cost of solving mask problem 
    // ans = cost of solving mask problem + cost of monitor 
    // as monitor cost is increasing so we can take minimum out of all possible dp[mask];
    dp[0]=0;
    int ans=INF;
    for(int i=0;i<n;i++){
        for(int mask=0;mask<(1<<m);mask++){
            dp[f[i][3]|mask]= min(dp[f[i][3]|mask] ,dp[mask] + f[i][0]);
        }
        ans=min(ans,dp[(1<<m)-1]+b*f[i][1]);
    }
    if(ans>=INF) ans=-1;
    cout<<ans<<endl;
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

//https://codeforces.com/contest/417/problem/D
