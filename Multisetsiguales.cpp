
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

    int tamanoDeA;
    cin >> tamanoDeA;

    hash_table<int,int> tablaDeFrecuenciasDeA;

    for(int indice = 0; indice < tamanoDeA; indice = indice + 1){
        int valorLeido;
        cin >> valorLeido;
        int frecuenciaVieja = tablaDeFrecuenciasDeA[valorLeido];
        tablaDeFrecuenciasDeA[valorLeido] = frecuenciaVieja + 1;
    }

    int tamanoDeB;
    cin >> tamanoDeB;

    bool sonIguales;
    if(tamanoDeA == tamanoDeB){
        sonIguales = true;
    } else {
        sonIguales = false;
    }

    for(int indice = 0; indice < tamanoDeB; indice = indice + 1){
        int valorLeido;
        cin >> valorLeido;

        if(sonIguales == true){
            bool existeElValor = tablaDeFrecuenciasDeA.contains(valorLeido);
            if(existeElValor == true){
                int frecuenciaActual = tablaDeFrecuenciasDeA[valorLeido];
                if(frecuenciaActual > 0){
                    tablaDeFrecuenciasDeA[valorLeido] = frecuenciaActual - 1;
                } else {
                    sonIguales = false;
                }
            } else {
                sonIguales = false;
            }
        }
    }

    if(sonIguales == true){
        cout << "SI" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}