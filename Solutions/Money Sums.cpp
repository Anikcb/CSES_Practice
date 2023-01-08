//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

//using    namespace __gnu_pbds;
using namespace std;


/*** Typedef ***/
typedef long long ll;
typedef unsigned long long ull;


/*** STLs ***/
typedef vector <ll> vll;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef queue <ll> qll;
typedef stack <ll> stll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;
typedef map<string,ll> msl;
typedef priority_queue<ll> pql;
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
ll A[N*10];
ll B[N*10];

void subsetSum(vector<ll> const &A, ll k)
{

    ll n = A.size();
    bool T[n + 1][k + 1];

    for (int j = 1; j <= k; j++)
        T[0][j] = false;

    for (int i = 0; i <= n; i++)
        T[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (A[i - 1] > j)
            {
                T[i][j] = T[i - 1][j];
            }
            else
            {
                T[i][j] = T[i - 1][j] || T[i - 1][j - A[i - 1]];
            }
        }
    }
    vll v;
    foR1(k)
    {
        if(T[n][i])v.pb(i);
    }
    cout<<SZ(v)<<endl;
    prnt(v,0,SZ(v));
}


int main()
{
    IOS;
    ll tst=1;
    //cin>>tst;
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        ll n,sum=0;
        cin>>n;
        vll v(n);
        foR0(n)cin>>v[i],sum+=v[i];
        subsetSum(v,sum);


    }


    return 0;
}
