#ifndef AHOCORASICK_HPP_
#define AHOCORASICK_HPP_
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class AC_State
{
    public: 
        AC_State* suffixLink;
        AC_State* parent;
        char parentChar;
        map<char,AC_State*> children;
        vector<int> wordIds; // id's of words that end with this node
        AC_State()
        {
            suffixLink=NULL;
            parent=NULL;
            parentChar='\0';
        }
};
class AhoCorasick
{
    private:
        AC_State* root;
        string text;
        int * results;
        void prepare();
        void trieFonk(string s, int wId);
        void bfs(AC_State *state);
        void run();
        void deleteStates();
    public:
        AhoCorasick(string txt, vector<string> queries);
        int * get_result();
        ~AhoCorasick();
};

int *AhoCorasick::get_result()
{
    return results;
}
AhoCorasick::~AhoCorasick()
{
    deleteStates();
}
void AhoCorasick::run()
{
    AC_State *state=root;
    for(auto s:text)
    {
        while(true)
        {
            if(!state->wordIds.empty())
            {
                for(auto x:state->wordIds)
                {
                    results[x]++;
                }
            }
            if(state->children[s]!=0)
            {
                state=state->children[s];
                break;
            }
            if(state==root) break;
            state=state->suffixLink;
        }
    }
}
AhoCorasick::AhoCorasick(string txt, vector<string> queries)
{
    text=txt+'$';
    root=new AC_State;
    for(int i=0;i<queries.size();i++)
    {
        trieFonk(queries[i], i);
    }
    results = new int[queries.size()];
    prepare();
    run();
}
void AhoCorasick::trieFonk(string s, int wId)
{
    AC_State *state=root;
    for(char ch:s)
    {
        if(state->children[ch]!=0)
        {
            state=state->children[ch];
        }
        else
        {
            AC_State *t =new AC_State;
            state->children[ch]=t;
            t->parent=state;
            state=t;
            state->parentChar=ch;
        }
    }
    state->wordIds.push_back(wId);
}
void AhoCorasick::bfs(AC_State *state)
{
    if(state==root)
    {
        state->suffixLink=root;
        return;
    }
    if(state->parent==root)
    {
        state->suffixLink=root;
        return;
    }

    AC_State *currentBest = state->parent->suffixLink;

    if(currentBest->children[state->parentChar]!=NULL)
    {
        state->suffixLink = currentBest->children[state->parentChar];
        
    } 
    while(true)
    {
        if(currentBest->children[state->parentChar]!=NULL)
		{
			state->suffixLink = currentBest->children[state->parentChar];
			break;
		}

        if(currentBest==root) 
        {
            state->suffixLink = root;
            break;
        }
        
        currentBest = currentBest->suffixLink;
    }  
}
void AhoCorasick::prepare()
{
    queue<AC_State*> state_q;
    state_q.push(root);
    while(!state_q.empty())
    {
        AC_State *current = state_q.front();
        state_q.pop();
        bfs(current);
        for(auto x:current->children)
        {
            if(x.second!=NULL) state_q.push(x.second);
        }

    }
}


void AhoCorasick::deleteStates()
{
    queue<AC_State*> state_q;
    state_q.push(root);
    while(!state_q.empty())
    {
        AC_State *current = state_q.front();
        state_q.pop();
        
        for(auto x:current->children)
        {
            if(x.second!=NULL) state_q.push(x.second);
        }
        delete current;

    }
    delete[] results;
}


#endif // AHOCORASICK_HPP_