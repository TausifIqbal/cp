#include <bits/stdc++.h>
using namespace std;
// #define int long long 
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

void add(int &x , int &y){
    x=x+y;
    if(x>mod){
        x=x-mod;
    }
}

void solve(){
    int R,G;
    cin>>R>>G;
    vector<vector<int>> dp(2,vector<int>(R+1));
    // dp(i,j) --> number of ways to form  tower of height i using only j red blocks 
    dp[0][0]=1;
    int ans=0;
    int s=R+G;
    int H=0;
    for(int i=1;i<=s;i++){
        H+=1;
        s-=i;
    }
    for(int l=1;l<=H;l++){
        for(int r=R;r>=0;r--){
            dp[l%2][r]=0;
        }
        int temp=0;
        for(int r=0;r<=R;r++){
            // I have to use only r block upto level l

            // use l red blocks out of r red blocks at this level
            if(r-l>=0){
                add(dp[l%2][r] , dp[(l-1)%2][r-l]);
            }

            // use all r red blocks before this level check green blocks are available are not
            int green_block= l*(l+1)/2 -r;
            if(green_block<=G &&  r<= (l-1)*l/2 ){
                add(dp[l%2][r] , dp[(l-1)%2][r]);
            }

            add(temp,dp[l%2][r]);

        }
        
        if(temp!=0){
            ans=temp;
        }

    }
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

//https://codeforces.com/contest/478/problem/D
