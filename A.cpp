#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string r, m;
    cin >> r >> m;

    unordered_map<char,int> freq; // frecuencia de cada letra en m
    for(char c : m) freq[c]++;

    bool posible = true;
    for(char c : r){
        if(freq[c] > 0){
            freq[c]--; // "gasto" una letra
        } else {
            posible = false;
            break;
        }
    }

    cout << (posible ? "SI" : "NO") << "\n";
    return 0;
}