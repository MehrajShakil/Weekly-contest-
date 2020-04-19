// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp> //order_of_key return number of elements less than x, find_by_order return index (pointer use kora lgbe)

using namespace std;
using namespace __gnu_pbds;

#define ull    unsigned long long
#define ll     long long
#define ios    ios::sync_with_stdio(0);cin.tie(0);
#define ses    "\n"
#define all(x) (x).begin(), (x).end()
//#define INF   ((int)2e18)
#define ii pair<ll, ll>

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const int N=1e6+5;
const ll M=1e18;

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)
        return 1;
    if(e%2==0)
    {
        ll t=bigmod(p,e/2,M);
        return (T)((t*t)%M);
    }
    return (T)((ll)bigmod(p,e-1,M)*(ll)p)%M;
}

template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);   // when M is prime;
}
typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

struct Edge
{
    int u, vv;
    bool operator<(Edge const& other)
    {
        return vv > other.vv;
    }
}; // eta joss jinis.krsukal er jnno and sort 1 out of 3 or more er jnno better


//***********************************************  The END **********************************************************************************************************************************


/////////////////////////////////////////////////////////////////////////////
// 1st approach::

bitset<10000001> bs;
vector<ll> primes;

void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;

    for(ll i=2; i<=10000000; i+=2)
        bs[i]=0;
    primes.push_back(2);
    for(ll i =3; i<=10000000; i+=2)
    {
        if(bs[i])
        {
                //cout<<i<<" ";
            primes.push_back(i);
            for(ll j=i*i; j<=10000000; j+=(i+i))
            {
                bs[j]=0;
            }
        }
    }
}


void Factor(ll n , ll &mx){
ll nn=n;
ll ans=1;
for(ll i=0;i<primes.size() ;i++){
     ll p = primes[i],freq=0;
     if(n<p)break;
     while(n%p==0){
                n/=p;
                freq++;
     }
     mx=max(mx,freq);
}

if(n>1)mx=max(mx,1LL);
}

////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{
     ios
    sieve();
    ll t,tc=0;
    cin>>t;
    while(t--)
    {
        ll n,mx=0;
        cin>>n;
        Factor(n,mx);
        cout<<mx<<ses;
    }
}

/*

In this problem I have to find the smallest numbers of square free factor.

/// Ok, so what is square free number?? A number that can't carry more than one prime is called square free factor.

ex : 6 , 15 etc.

20 is not square free because 20 = 2^2 * 5^1
  here 2 is twice time.

in this problem approach could be the maximum occurance of a prime factor.

let 6 = 1 * 6 ans is 1 because 1 can't be factor.
    8 = 2 * 2 * 2.   ans is 3.
    20 = 2 * 2 * 5. ans is 2. because 20 = 10 * 2 both are  square free.


 */
