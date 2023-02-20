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
typedef vector <pair <ll, ll> > vpll;
typedef vector <pair <int, int> > vpii;
typedef priority_queue<ll,vector<ll>,greater<ll> > npql;


/*** Values ***/
const int N = 200005;
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


ll n, t[4*N];

void build(ll v, ll tl, ll tr)
{
    if (tl == tr){
        t[v] = 1;
    }
    else{
        ll tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr){
        t[v] = new_val;
    }
    else{
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll find_kth(ll v, ll tl, ll tr, ll k) {
    if (k > t[v])return -1;
    if (tl == tr)return tl;
    ll tm = (tl + tr) / 2;
    if (t[v*2] >= k)
        return find_kth(v*2, tl, tm, k);
    else
        return find_kth(v*2+1, tm+1, tr, k - t[v*2]);
}

int main()
{
    IOS;
    ll tst=1;
    //cin>>tst;
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        cin>>n;
        vll A(n);
        forIn(A,n);
        build(1,0,n-1);
        ll q=n;
        while(q--)
        {
            ll a;
            cin>>a;
            ll p=find_kth(1,0,n-1,a);
            update(1,0,n-1,p,0);
            cout<<A[p]<<" ";
        }
        cout<<endl;


    }


    return 0;
}
