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

    int cantidadDeNumeros;
    int cantidadDeConsultas;
    cin >> cantidadDeNumeros >> cantidadDeConsultas;

    hash_table<int,int> tablaDeFrecuencias;

    for(int indice = 0; indice < cantidadDeNumeros; indice = indice + 1){
        int numeroLeido;
        cin >> numeroLeido;
        int frecuenciaActual = tablaDeFrecuencias[numeroLeido];
        frecuenciaActual = frecuenciaActual + 1;
        tablaDeFrecuencias[numeroLeido] = frecuenciaActual;
    }

    for(int indiceConsulta = 0; indiceConsulta < cantidadDeConsultas; indiceConsulta = indiceConsulta + 1){
        int numeroConsultado;
        cin >> numeroConsultado;

        bool existeEnLaTabla = tablaDeFrecuencias.contains(numeroConsultado);
        int respuesta;
        if(existeEnLaTabla == true){
            respuesta = tablaDeFrecuencias[numeroConsultado];
        } else {
            respuesta = 0;
        }

        cout << respuesta << "\n";
    }

    return 0;
}