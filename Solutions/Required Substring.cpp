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
ll dp[1005][105];
ll failure[N];

void build_failure_function(string pattern, ll m)
{
    ll len = 0,i=1;
    failure[0] = 0;
    while (i < m) {
        if (pattern[i] == pattern[len])
        {
            len++;
            failure[i] = len;
            i++;
        }
        else {
            if (len != 0)len = failure[len - 1];
            else failure[i] = 0,i++;
        }
    }
}

ll fun(ll i,ll n,ll j,string s,ll m)
{
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==n)return dp[i][j] = (j==m?1:0);
    if(j==m)return dp[i][j] = (26*fun(i+1,n,j,s,m))%MOD;
    ll res=0;
    for(ll k=0;k<26;k++)
    {
        ll p=j;
        while(true)
        {
            if(s[p]-'A'==k){p++;break;}
            else if(p>0)p=failure[p-1];
            else break;
        }
        res=(res+fun(i+1,n,p,s,m))%MOD;
    }
    return dp[i][j] = res;
}

int main()
{
    IOS;
    ll tst=1;
    //cin>>tst;
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        ll n;
        string s;
        cin>>n>>s;
        build_failure_function(s,SZ(s));
        memn(dp);
        cout<<fun(0,n,0,s,SZ(s));


    }


    return 0;
}
