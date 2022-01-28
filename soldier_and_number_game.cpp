#include <bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int, int> pii; 
#define ll long long
#define ld long double
#define ar array
const int mxN=5e6+4;
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

int fact[mxN];
int lcp[mxN];
int p[mxN];
void sieve(){   
    vector<bool> prime(mxN,true);
    for(int i=2;i<mxN;i++){
        if(prime[i]){
            for(int j=i;j<mxN;j+=i){
                lcp[j]=i;
                prime[j]=false;
            }
        }
    }

}
int get_power(int x){
    int res=0;
    while(x!=1){
        int count=0;
        int divisor = lcp[x];
        while( x>0 && x%divisor==0){
            x/=divisor;
            count++;
        }
        res+=count;
    }
    return res;
}
void precal(){
    sieve();
    for(int i=2;i<mxN;i++){
        p[i]=get_power(i);
    }
    fact[0]=0;
    fact[1]=0;
    for(int i=2;i<mxN;i++){
        fact[i]=fact[i-1]+p[i];
    }

}

void solve(){
    int a,b;
    cin>>a>>b;
    cout<<fact[a]-fact[b]<<"\n";
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
    precal();
    int t=1;
    cin>>t;
    
    while(t--){
       // cout<<"Case #"<<i<<": ";
        solve();
      //  cout<<endl;
      //  i++;
    }
    return 0;
   
}  

//https://codeforces.com/problemset/problem/546/D
