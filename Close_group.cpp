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
// const ll INF=1e17;
const int INF= 1e10;
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



void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> edge(n,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        --x,--y;
        edge[x][y]=true;
        edge[y][x]=true;
    }
    vector<bool > clique((1<<n),true);
    for(int mask=1;mask<(1<<n);mask++){
        int ok=true;
        for(int u=0;u<n;u++){
            if(mask&(1<<u)){
                for(int v=0;v<n;v++){
                    if(mask&(1<<v) && v!=u){
                        if(!edge[v][u]){
                            ok=false;
                            clique[mask]=false;
                            break;
                        }
                    }
                }

                if(!ok){
                    break;
                }
            }
        }
    }

    vector<int> dp((1<<n),INF);
    for(int mask=1;mask<(1<<n);mask++){
        if(clique[mask]) dp[mask]=1;
        else{
            for(int u=mask;u>0;u=mask&(u-1)){
                int v= mask^u;
                dp[mask]=min(dp[mask],dp[u]+dp[v]);
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
   
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

//https://atcoder.jp/contests/abc187/tasks/abc187_f
