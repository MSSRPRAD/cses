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
    int n,m; see(n,m);
    int a[n];
    seea(a,0,n);
    int dp[n+1][m+1];
    // dp[i][j] = no of ways to fill upto ith element if last element is j
    // Base case i = 0:
    rep(j, 0, m+1){
      dp[0][j] = (a[0] == 0) ? 1 : 0;
    }
    if (a[0] != 0) {
      dp[0][a[0]] = 1;
    }
    // Recursive Case
    rep(i, 1, n+1){
      if(a[i] == 0){
        rep(j, 1, m+1){
          dp[i][j] = dp[i-1][j]%md;
          if(j>1) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%md;
          if(j!=m) dp[i][j] = (dp[i][j] + dp[i-1][j+1])%md;
        }
      } else {
        rep(j, 1, m+1){
          if(j == a[i]){
            dp[i][j] = dp[i-1][j]%md;
            if(j>1) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%md;
            if(j!=m) dp[i][j] = (dp[i][j] + dp[i-1][j+1])%md;
          } else {
            dp[i][j] = 0;
          }
        }
      }
    }
    int s = 0;
    rep(i, 1, m + 1){
        s = (s + dp[n-1][i]) % md;
    }
    put(s%md);
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
