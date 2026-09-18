#include <bits/stdc++.h>
using namespace std;

template <class K, class V>
class hash_table
{
    struct node
    {
        K key;
        V value;
        node * next = nullptr;
    };

    vector<node*> table;
    size_t m;
    size_t n = 0;

public:
    hash_table(size_t buckets = 1000003) : table(buckets, nullptr), m(buckets) {}

    ~hash_table()
    {
        for(node * head : table) free(head);
    }

    V & operator [] (const K & key)
    {
        node ** np = nullptr;
        if(!search(np, key))
        {
            *np = new node{key, V()};
            n++;
        }
        return (*np)->value;
    }

    bool contains(const K & key)
    {
        node ** np;
        return search(np, key);
    }

protected:
    size_t hash(const K & key) const { return std::hash<K>{}(key) % m; }

    bool search(node **& np, const K & key)
    {
        np = &table[hash(key)];
        while(*np && (*np)->key != key)
            np = &(*np)->next;
        return *np != nullptr;
    }

    void free(node * n)
    {
        while(n) { node * s = n->next; delete n; n = s; }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);

    hash_table<char,int> lastSeen;
    for(char c = 33; c <= 126; ++c) lastSeen[c] = -1; // inicializa todo en -1

    int left = 0, best = 0;
    for(int right = 0; right < (int)s.size(); right++){
        char c = s[right];
        if(lastSeen[c] >= left)
            left = lastSeen[c] + 1;
        lastSeen[c] = right;
        best = max(best, right - left + 1);
    }

    cout << best << "\n";
    return 0;
}