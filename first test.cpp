#include <bits/stdc++.h>
#include "ahocorasick.hpp"
#include "graph.hpp"
using namespace std;
#define pb push_back
template <class T>
struct Compare {
    constexpr bool operator()(T const & a, T const & b) const noexcept { return a>b; }
};

template <class T> class priority_queue_less: public priority_queue<T, vector<T>, Compare<T>>{};



struct test : public Node
{
    int value;
};
int main(int argc, char const *argv[])
{
    


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
    
    return 0;
}
*/