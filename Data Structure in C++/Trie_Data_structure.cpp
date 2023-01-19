
#include<iostream>
using namespace std;

#define SZ 256

struct node{
    bool terminal;
    node *reflink[SZ];
    node()
    {
        terminal=false;
        int i;
        for(i=0; i<SZ; i++) reflink[i]=NULL;
    }
};

struct TRIE{
    node *root;
    /// Constructor
    TRIE();
    /// Utility Function
    void clear(node *temp, string word, int ind);
    void del(node *temp);
    /// User accessable function
    void insert(string word);
    int search(string key);
    void remove(string word);
    void deleteTRIE();

};

TRIE:: TRIE()
{
    root=new node();
}

void TRIE::insert(string word)
{
    node *cur=root;
    int i, len=word.size();
    for(i=0; i<len; i++)
    {
        if(cur->reflink[word[i]]==NULL) {
            cur->reflink[word[i]]=new node();
        }
        cur=cur->reflink[word[i]];
    }
    cur->terminal=true;
    return;
}


int TRIE::search(string key)
{
    node *cur=root;
    int i;
    for(i=0; i<key.size(); i++)
    {
        if(!cur->reflink[key[i]] || (cur->terminal && i!=key.size()-1)) return 3;
        cur=cur->reflink[key[i]];
    }
    if(cur->terminal) return 1;
    return 2;
}

void TRIE:: clear(node *temp, string word, int ind)
{
    if(ind==word.size())
    {
        temp->terminal=false;
        return;
    }
    if(temp->reflink[word[ind]]) clear(temp->reflink[word[ind]], word, ind+1);
    int i;
    for(i=0; i<SZ; i++)
    if(temp->reflink[i]) return;
    if(temp->terminal) return;
    delete(temp);
}

void TRIE:: remove(string word)
{
    clear(root, word, 0);
}

void TRIE:: del(node *temp)
{
    int i;
    for(i=0; i<SZ; i++)
    if(temp->reflink[i]) del(temp->reflink[i]);
    delete(temp);
}

void TRIE:: deleteTRIE()
{
    del(root);
}




void spidey()
{
    int n;
    cin>>n;
    string s[n];
    int i;
    TRIE x;
    for(i=0; i<n; i++)
    {
        cin>>s[i];
        x.insert(s[i]);
    }
    for(i=0; i<n; i++)
    {
        if(x.search(s[i])==3)
            cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    return;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        spidey();
    }
    return 0;
}


