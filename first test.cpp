#include <bits/stdc++.h>
#include "ahocorasick.hpp"
using namespace std;
#define pb push_back
template <class T>
struct Compare {
    constexpr bool operator()(T const & a, T const & b) const noexcept { return a>b; }
};

template <class T> class priority_queue_less: public priority_queue<T, vector<T>, Compare<T>>{};

int main(int argc, char const *argv[])
{

    string text;//text that patterns search in
    cin>>text;
    int q;
    cin>>q;
    vector<string> queries;// patterns
    for(int i=0;i<q;i++)
    {
        string s;
        cin>>s;
        queries.pb(s);
    }
    AhoCorasick aho(text, queries);
    int *rslt = aho.get_result();
    for(int i=0; i<q;i++)
    cout<<rslt[i]<<endl;

    return 0;
}
/*

int main(int argc, char const *argv[])
{

    
    vector<int> deneme;
    int x=0;
    do
    {
        cin>>x;
        deneme.push_back(x);

    }while(x!=0);
    cout<<endl<<endl;
    sort(deneme.begin(), deneme.end(), Compare<int>());
    for(auto a:deneme)
    {
        cout<<a<<" ";
    }
    re
    
    return 0;
}
*/