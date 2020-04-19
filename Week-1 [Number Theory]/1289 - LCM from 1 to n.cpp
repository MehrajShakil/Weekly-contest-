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

const int N=100000005;
const int M=6000000;
const ll mod = 1<<32;
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

vector<bool>bs(N,true);
int  primes[M];
unsigned int product[M];
int  cnt = 0;

void sieve()
{
    for(int  i = 2; i*i<N; i++){
            if(bs[i]){
                for(int j = i*i; j<N; j+=i){
                    bs[j] = false;
                }
            }
        }

        product[0] = 1;
        for(int  i = 2; i<N; i++){
            if(bs[i]){
                primes[cnt++] = i;
                product[cnt] = product[cnt-1]*i;
            }
        }
}

////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{
    //ios
    sieve();
    int t,cs=0;
    cin>>t;
    while(t--)
    {
        unsigned int n,ans=1;
        cin>>n;

        for(auto p : primes)
        {
            ll cnt=0;
            if(n<(p*p))
                break;
             int cur = n;
            while(cur/=p){
                cnt++;
            }
            cnt--;
            while(cnt--)ans*=p;
        }
        int pos = upper_bound(primes,primes+cnt,n)-primes;
        ans*=product[pos];
        cout<<"Case "<<++cs<<": "<<ans<<ses;
    }
    return 0;
}

/*
In this problem we have to find lcm between 1 to n.;

So, what is lcm??
in a short lcm is a number that is divides by every number between them.

let, lac(3,12,15);

3 = 3,6,9,12,15,18,21,24,27;
9 = 9,18,27,36;
6 = 6 , 12 , 18;

so,we find  18 and it is the smallest number that is divided by (3,6,9);

so,lcm is 18.

lets go how we find that using prime factor.

3 = 3^1;
9 = 3^2;
6 = 3^1 * 2^1.

the trick is we find maximum occuarence of a prime number between them.

so here maximum are = 3^2 * 2^1
                    = 9 * 2
                    = 18

so, lcm is 18.

*/


