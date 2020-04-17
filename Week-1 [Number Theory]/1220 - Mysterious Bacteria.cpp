
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

// █▀█─█──█──█▀█─█─█
// █▄█─█──█──█▄█─█▄█
// █─█─█▄─█▄─█─█─█─█


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
const ll MOD = 1000000007;

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
/*

*/
/////////////////////////////////////////////////////////////////////////////
vector<vector<ll> > adj;
vector<char> vis;


////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{
    ios
    ll t,tc=0;
    cin>>t;
    while(t--){
         ll n,cnt=0,gcd=0,neg=0;
         cin>>n;
         if(n<0){
                neg=1;
                n*=(-1LL);
         }
         while(!(n%2)){
                n/=2;
                cnt++;
         }
         gcd=__gcd(gcd,cnt);

         for(ll i=3;i*i<=n;i++){
               cnt=0;
               while(!(n%i)){
                n/=i;
                cnt++;
               }
         gcd=__gcd(gcd,cnt);
         }
         if(n>1){
               gcd=1;
         }
         if(neg){
                while(!(gcd%2)){
                      gcd/=2;
                }
         }
         cout<<"Case "<<++tc<<": "<<gcd<<ses;
    }
}
/*

 In this we have to find the greatest power of a number.

 let x = 4.
     x = 2^2.

     x = 15
     x = 15^1.

     x = 16.
     x = 2^4.

     x = -16
     x = -16^1.

     ok,so what is the approach to solve the problem.
     if we see the example.

     we find that the answer should be the gcd of prime factor of this number.

     let x = 15
         x = 3^1 * 5^1.
         here gcd = 1.

         x = 20;
         x = 2 * 2 * 5.
           = 2^2 * 5^1.
         here gcd = 1.

         For the negative number we know the power should be odd.

         x = -16.
         x = -2 * -2 * -2 * -2 can't because multiple give positive.
            so, the only possibilities
         x = -16^1.
         here power is odd.
     Alhamdulillah
*/

