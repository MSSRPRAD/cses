#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout<<'\n';
#define E cerr<<'\n';
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;


void solve(){
  int n; see(n);
  int coins[n];
  seea(coins,0,n);
  int sum = 0;
  rep(i, 0, n){
    sum += coins[i];
  }
  // dp[i][j] = is it possible to get sum of i using upto jth coins (including jth)
  bool dp[n+1][sum+1];
  dp[0][0] = true;
  rep(i, 1, n+1){
    // What all sums can we make using these coins?
    rep(j, 0, sum+1){
      dp[i][j] = dp[i-1][j]; // If we can get current sum without using current coin
      int k = j - coins[i-1];
      if(k >= 0 && dp[i-1][k]){
        // If we can get a sum of j-current coin without using the current coin
        dp[i][j] = true;
      }
    }
  }

  vector<int> sums;
  rep(SUM, 1, sum+1){
    if(dp[n][SUM]){
      sums.push_back(SUM);
    }
  }
  putl(sums.size());
  rep(i, 0, sums.size()){
    put(sums[i]);
  }
  return;
}

signed main(){
    IOS;
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}
