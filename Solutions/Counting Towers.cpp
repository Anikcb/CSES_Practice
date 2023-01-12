//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

//using    namespace __gnu_pbds;
using namespace std;


/*** Typedef ***/
typedef long long ll;
typedef unsigned long long ull;


/*** STLs ***/
typedef set <ll> sll;
typedef set <int> sii;
typedef queue <ll> qll;
typedef stack <ll> stll;
typedef vector <ll> vll;
typedef vector <int> vii;
typedef map <ll, ll> mll;
typedef map <int, int> mii;
typedef pair <ll, ll> pll;
typedef multiset <ll> msll;
typedef pair <int, int> pii;
typedef priority_queue<ll> pql;
typedef vector <pair <ll , ll> > vpll;
typedef vector <pair <int , int> > vpii;
typedef priority_queue<ll,vector<ll>,greater<ll> > npql;


/*** Values ***/
const int N = 100005;
const int MOD = 1000000007;
const int inf = 1234567890;
const ll INF = 1122334455667788990;


/*** Define Values ***/
#define     F                 first
#define     S                 second
#define     re                return
#define     MP                make_pair
#define     pb                push_back
#define     SZ(x)             ((ll) (x).size())
#define     EPS               10E-10
#define     iseq(a,b)         (fabs(a-b)<EPS)
#define     PI                3.141592653589793238462643
#define     HAR               0.57721566490153286060651209
#define     Ceil(a,b)         (a+b-1)/b
#define     gcd(a, b)         __gcd(a,b)
#define     lcm(a, b)         ((a)/gcd(a,b))*(b)
#define     input             freopen("input.txt","rt", stdin)
#define     output            freopen("output.txt","wt", stdout)
#define     all(v)            v.begin(),v.end()
#define     en                cout << '\n';
#define     no                cout << "NO" << '\n'
#define     yes               cout << "YES" << '\n'
#define     memz(u)           memset(u, 0, sizeof u)
#define     memn(u)           memset(u, -1, sizeof u)
#define     ps(x,y)           fixed<<setprecision(y)<<x
#define     foR0(num)         for(ll i = 0; i < num; i++)
#define     foR1(num)         for(ll i = 1; i <= num; i++)
#define     rep(i, x, n)      for (ll i = x, _n = (n); i < _n; ++i)
#define     forIn(arr, num)   for(ll i = 0; i < num; i++) cin>>arr[i];
#define     forIn1(arr, num)  for(ll i = 1; i <= num; i++) cin>>arr[i];
#define     Unique(X)         (X).resize(unique(all(X))-(X).begin())
#define     IOS               ios_base::sync_with_stdio(false); cin.tie(NULL);
#define     prnt(arr,x,num)   for(ll i=x; i<num;i++)cout<<arr[i]<<(i + 1 < num ? ' ' : '\n');

//__uint128_t


int main()
{
    IOS;
    ll tst=1;
//    cin>>tst;
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        ll n=1000005;
        vector< vector<ll> >dp(n+1,vector<ll>(9,0));
        foR0(8)dp[0][i]=1;
        rep(i,1,n)
        {
            rep(j,0,8)
            {
                if(j==0 || j==2 ||j==3 ||j==4 ||j==5){
                    dp[i][j]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][3]+dp[i-1][4]+dp[i-1][5])%MOD;
                }
                else{
                    dp[i][j]=(dp[i-1][2]+dp[i-1][6]+dp[i-1][7])%MOD;
                }
            }
        }

        ll t;
        cin>>t;
        while(t--)
        {
            cin>>n;
            cout<<(dp[n-1][2]+dp[n-1][6])%MOD<<endl;
        }


    }


    return 0;
}
