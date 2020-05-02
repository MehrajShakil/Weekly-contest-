
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

int KMP(string text, string pattern)
{

    vector<int> prefix = compute_prefix(pattern);

    int matched_pos = 0,cnt=0;

    for(int current = 0 ; current<text.size() ; current++)
    {
        while(matched_pos>0 and pattern[matched_pos]!=text[current])
        {
            matched_pos = prefix[matched_pos-1];
        }
        if(pattern[matched_pos]==text[current])
        {
            matched_pos = matched_pos+1;
        }
        if(matched_pos==pattern.size())
        {
            cnt++;
            matched_pos=prefix[matched_pos-1];
        }

    }

    return cnt;
}


int main()
{

    int t,tc=0;
    cin >> t;
    while(t--)
    {
        string text, pattern;
        cin >> text >> pattern;

        cout<<"Case "<<++tc<<": "<<KMP(text, pattern)<<'\n';
    }

}
