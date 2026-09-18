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

    int cantidadDeElementos;
    long long valorObjetivo;
    cin >> cantidadDeElementos >> valorObjetivo;

    vector<long long> arregloDeNumeros(cantidadDeElementos);
    for(int indice = 0; indice < cantidadDeElementos; indice = indice + 1){
        long long numeroLeido;
        cin >> numeroLeido;
        arregloDeNumeros[indice] = numeroLeido;
    }

    hash_table<long long,bool> conjuntoDeVistos;
    bool seEncontroLaPareja = false;

    for(int indice = 0; indice < cantidadDeElementos; indice = indice + 1){
        long long numeroActual = arregloDeNumeros[indice];
        long long numeroQueFalta = valorObjetivo - numeroActual;

        bool yaVimosElComplemento = conjuntoDeVistos.contains(numeroQueFalta);

        if(yaVimosElComplemento == true){
            seEncontroLaPareja = true;
            break;
        }

        conjuntoDeVistos[numeroActual] = true;
    }

    if(seEncontroLaPareja == true){
        cout << "SI" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}