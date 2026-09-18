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

    string J, S;
    cin >> J >> S;

    hash_table<char,bool> joyas;
    for(char c : J) joyas[c] = true;

    int count = 0;
    for(char c : S)
        if(joyas.contains(c)) count++;

    cout << count << "\n";
    return 0;
}