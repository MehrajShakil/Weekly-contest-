
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


vector<ll> arr[100001];
/////////////////////////////////////////////////////////////////////////////

vector<ll> primes;
bitset<100001> bs;


void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=2; i<=100000; i+=2)
        bs[i]=0;

    for(ll i=3; i<=100000; i+=2)
    {
        if(bs[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=100000; j+=(i+i))
            {
                bs[j]=0;
            }
        }
    }
}

ll PrimeFactor(ll n)
{
    ll nn=n;
    ll ans=1;
    for(ll i=0; i<primes.size() && (primes[i]*primes[i]) <=nn ; i++)
    {
        ll freq=0;

        while(n%primes[i]==0)
        {
            n/=primes[i];
            freq++;
        }
        freq*=2;      /// because when i*i == i^2 == so, we multiply freq with 2.
        freq++;
        ans*=freq;
        if(n<primes[i])
            break;
    }
    if(n>1)
    {
        ans*=3;
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{
    ios
    sieve();
    ll t,tc=0;
    for(ll i=1; i<=100100; i++)
    {
        arr[PrimeFactor(i)].push_back(i*i);
    }
    cin>>t;
    while(t--)
    {
        ll k,a,b,ans=0;
        cin>>k>>a>>b;
        cout<<upper_bound(arr[k].begin(),arr[k].end(),b)-lower_bound(arr[k].begin(),arr[k].end(),a)<<ses;
    }

}
/*

In this problem we have to find number of odd divisors in a range.

ok, so here's tell that divisors should be odd.

we know that only perfect square carry odd divisors.

  /// Perfect square means a number which can be represent by two equal numbers let 9 = 3*3 , 25 = 5*5 etc.....

so, how can we find divisors of e number efficiently

we know x  = p1^e1 * p2^e2 * p3^e3 .......
here pi is a primer number and ei is the occarunce of that prime.

we can find divisors using PF.

D(x) = (e1+1)*(e2+1)*.....(en+1).

D(x) returns number of divisors of x.

but this problem limit is too high 10^10.
you can't go up to 10^10.
because 10^5 * 10^5 = 10^10.
Or square root of(10^10)=10^5.

so, if we can get 10^5 divisors then we can easily find 10^10 divisors.

let x = 36
    x = 2^2 * 3^2
    D(x) = (2+1) * (2+1)
         = 9.

    again,
    x = 6 * 6;
      = 6^2.

    so 36 is a perfect square.

    6^2 = (2^1 * 3^1)^2
        = 2^2 * 3*2
        = (2+1) * (2+1).
        = 9.

  it can be proved that we can find divisors of x by square root of x.

*/
