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
typedef vector <pair <ll, ll> > vpll;
typedef map<string,ll> msl;
typedef priority_queue<ll> pql;
typedef priority_queue<ll,vector<ll>,greater<ll> > npql;


/*** Values ***/
const int N = 100005;
const int MOD = 1000000007;
const int inf = 1234567890;
const ll INF = 1122334455667788990;


/*** Define Values ***/
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

ll R=6,C=6;
void mulMat(ll F[7][7], ll M[7][7])
{
    ll rslt[R][C];

    for (ll i = 0; i < R; i++)
    {
        for (ll j = 0; j < C; j++)
        {
            rslt[i][j] = 0;
            for (ll k = 0; k < R; k++)
            {
                rslt[i][j] = (rslt[i][j]+(F[i][k] * M[k][j])%MOD)%MOD;
            }
        }
    }

    for(ll i=0; i<R; i++)
    {
        for(ll j=0; j<C; j++)
        {
            F[i][j]=rslt[i][j];
        }
    }
}


void power(ll F[7][7], ll n)
{
    if (n == 0 || n == 1)return;
    ll M[7][7] = {{1,1,1,1,1,1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
    power(F, n / 2);
    mulMat(F, F);
    if (n&1)mulMat(F, M);
}

ll matrix_expo(ll n,ll arr[])
{
    ll F[7][7] = {{1,1,1,1,1,1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
    if (n == 0)return 0;
    power(F, n);

    ll res=0;
    for(ll i=0; i<C; i++)
    {
        res=(res+(F[0][i]*arr[i])%MOD)%MOD;
    }
    return res;
}


int main()
{
    IOS;
    ll tst=1;
//    cin>>tst;
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        ll arr[]= {32,16,8,4,2,1};
        ll n;
        cin>>n;
        if(n<=6)cout<<arr[6-n]<<endl;
        else
        {
            ll val = matrix_expo(n-6, arr);
            cout<<val<<endl;
        }

    }


    return 0;
}
