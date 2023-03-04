#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin>>arr[i];
#define     IOS               ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);




struct data
{
    ll sum, pref, suff, ans;
} t[4*200005];

data combine(data l, data r)
{
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

data make_data(ll val)
{
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0ll, val);
    return res;
}

void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = make_data(a[tl]);
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        t[v] = make_data(new_val);
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

data query(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return make_data(0);
    if (l == tl && r == tr)
        return t[v];
    ll tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)),
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}


int main()
{
    IOS;
    ll tst=1;
    //cin>>tst;
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        ll n,a,b,c,q;
        cin>>n>>q;
        ll A[n+5];
        forIn(A,n);
        build(A,1,0,n-1);
        while(q--)
        {
            cin>>a>>b>>c;
            if(a==2){
                data d=query(1,0,n-1,b-1,c-1);
                cout<<d.pref<<endl;
            }
            else update(1,0,n-1,b-1,c);
        }


    }


    return 0;
}
