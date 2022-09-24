//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include<bits/stdc++.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
#include <time.h>


//using    namespace __gnu_pbds;
using namespace std;


/*** Typedef ***/
typedef long long ll;
typedef unsigned long long ull;



/*** Input ***/
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define scln1(a) scanf("%lld",&a)
#define scln2(a,b) scanf("%lld %lld",&a,&b)


/*** Output ***/
#define pf1(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfln1(a) printf("%lld\n",a)
#define pfln2(a,b) printf("%lld %lld\n",a,b)


/*** Loops ***/
#define foR0(num) for(ll i = 0; i < num; i++)
#define foR1(num) for(ll i = 1; i <= num; i++)
#define foRev(num) for(ll i = num - 1; i >= 0; i--)
#define rep(i, x, n) for (ll i = x, _n = (n); i < _n; ++i)
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin>>arr[i];
#define forIn1(arr, num) for(ll i = 1; i <= num; i++) cin>>arr[i];



/*** Define Values ***/

#define     ff                first
#define     ss                second
#define     re                return
#define     MP                make_pair
#define     pb                push_back
#define     SZ(x)             ((ll) (x).size())


#define     EPS               10E-10
#define     mxx               100005
#define     MOD               1000000007
#define     iseq(a,b)         (fabs(a-b)<EPS)
#define     PI                3.141592653589793238462643
#define     HAR               0.57721566490153286060651209


#define     Ceil(a,b)         (a+b-1)/b
#define     gcd(a, b)         __gcd(a,b)
#define     min3(a,b,c)       min(a,min(b,c))
#define     max3(a,b,c)       max(a,max(b,c))
#define     lcm(a, b)         ((a)/gcd(a,b))*(b)
#define     min4(a,b,c,d)     min(d,min(a,min(b,c)))
#define     max4(a,b,c,d)     max(d,max(a,max(b,c)))
#define     input             freopen("input.txt","rt", stdin)
#define     output            freopen("output.txt","wt", stdout)


#define     all(v)            v.begin(),v.end()
#define     memz(u)           memset(u, 0, sizeof u)
#define     memn(u)           memset(u, -1, sizeof u)
#define     ps(x,y)           fixed<<setprecision(y)<<x
#define     for2D0(n,m)       for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)
#define     for2D1(n,m)       for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)
#define     Unique(X)         (X).resize(unique(all(X))-(X).begin())
#define     get_pos(c,x)      (lower_bound(c.begin(),c.end(),x)-c.begin())
#define     get_pos_up(c,x)   (upper_bound(c.begin(),c.end(),x)-c.begin())
#define     IOS               ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


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


/*** BitWise Operations
///int Set(int N,int pos){return N=N | (1<<pos);}
///int reset(int N,int pos){return N= N & ~(1<<pos);}
///bool check(int N,int pos){return (bool)(N & (1<<pos));}
***/


/*** Grids
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
***/


/*** Functions
///transform(data.begin(), data.end(), data.begin(),[](unsigned char c){ return std::tolower(c); });
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
///ll toint(string s){ll n=0,k=1;for(int i=s.size()-1; i>=0; i--){n += ((s[i]-'0')*k);k*=10;}return n;}
///string tostring(ll x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}
///bool sortinrev(const pair<ll,ll> &a,const pair<ll,ll> &b)return (a.first > b.first);
///prime[]={2,4,2,4,6,2} //start loop from 29 to do prime factorization
///auto it = lower_bound(my_multiset.begin(), my_multiset.end(), 3);
///const auto pos = distance(my_multiset.begin(), it);
///priority_queue< pll ,vector<pll>,greater<pll> >p;
///lower_bound(all(v),r+1)-lower_bound(all(v),l);
///cout<<*X.find_by_order(0)<<endl;
///cout<<X.order_of_key(-5)<<endl;
///set< pair<int,int> >s;
///pair<int,int> p={3,2};
///auto lb=lower_bound(s.begin(),s.end(),p);
///cout<<(*lb).first<<" "<<(*lb).second<<endl;
***/


/*** Some Prints ***/
#define en cout << '\n';
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'

pll res;
ll fx[]= {1,-1,0,0},fy[]= {0,0,1,-1},row,col;
char cell[1005][1005];
ll d[1005][1005],dis[1005][1005];
bool visM[1005][1005],visA[1005][1005];
map< ll, map< ll, pll> >par;

void bfsM()
{
    queue< pll >q;
    for2D0(row,col){
        d[i][j]=1e12;
        if(cell[i][j]=='M'){
            q.push({i,j});
            visM[i][j]=true;
            d[i][j]=0;
        }
    }

    while(!q.empty()) {
        pll top=q.front();
        q.pop();
        for(ll k=0; k<4; k++) {
            ll tx=top.ff+fx[k],ty=top.ss+fy[k];
            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!='#' && cell[tx][ty]!='A' && visM[tx][ty]==0)
            {
                visM[tx][ty]=1;
                d[tx][ty]=d[top.ff][top.ss]+1;
                q.push(MP(tx,ty));
            }
        }
    }
}


void bfsA(ll sx,ll sy)
{
    visA[sx][sy]=1;
    dis[sx][sy]=0;
    queue< pll >q;
    q.push(MP(sx,sy));
    while(!q.empty()) {
        pll top=q.front();
        q.pop();
        for(ll k=0; k<4; k++) {
            ll tx=top.ff+fx[k],ty=top.ss+fy[k];
            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!='M' && cell[tx][ty]!='#' && visA[tx][ty]==0)
            {
                visA[tx][ty]=1;
                if(dis[top.ff][top.ss]+1>=d[tx][ty])continue;

                dis[tx][ty]=dis[top.ff][top.ss]+1;
                par[tx][ty]={top.ff,top.ss};
                if(tx==row-1 || ty==col-1 || tx==0 || ty==0){
                    res.ff=tx;
                    res.ss=ty;
                    return;
                }
                q.push(MP(tx,ty));
            }
        }
    }
}


int main()
{
    IOS;
    ll tst=1;
    //cin>>tst;
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        ll a=-1,b=-1;
        res.ff=-1;res.ss=-1;
        cin>>row>>col;
        for2D0(row,col)
        {
            cin>>cell[i][j];
            if(cell[i][j]=='A')a=i,b=j;
        }
        if(a==row-1 || b==col-1){cout<<"YES"<<endl;cout<<0<<endl;continue;}
        bfsM();
        bfsA(a,b);
        if(res.ff==-1)cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            vector<char>v;
            while(cell[res.ff][res.ss]!='A')
            {
                pll p=par[res.ff][res.ss];
                if(res.ff-p.ff==-1)v.pb('U');
                else if(res.ff-p.ff==1)v.pb('D');
                else if(res.ss-p.ss==-1)v.pb('L');
                else v.pb('R');
                res.ff=p.ff;
                res.ss=p.ss;
            }
            reverse(all(v));
            cout<<SZ(v)<<endl;
            foR0(SZ(v))cout<<v[i];
            cout<<endl;
        }
















    }


    return 0;
}
