
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

using ll =long long;

vector<int>compute_prefix(string pattern)
{
    int n = pattern.size();
    vector<int> prefix(n+1);
    prefix[0]=0;
    int k=0;
    for(int i=1; i<n; i++)
    {
        while(k>0 and pattern[k]!=pattern[i])
        {
            k = prefix[k-1];
        }

        if(pattern[k]==pattern[i])
        {
            k++;
        }

        prefix[i]=k;
    }
    return prefix;
}

int Root(string text)
{
    vector<int> prefix = compute_prefix(text);

    int cur = text.size() , ans=0;
    int n = text.size();

    while(cur){
        cur = prefix[cur-1];
        if(n%(n-cur)==0){
                return n/(n-cur);
        }
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string text;
    while(cin >> text )
    {
        if(text=="*")return 0;
        cout << Root(text) << '\n';
    }

}
