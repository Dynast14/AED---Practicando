#include <bits/stdc++.h>
#include <iostream>
    using namespace std;

int main2(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string J, S;
    cin >> J >> S;

    unordered_set<char> joyas(J.begin(), J.end()); // O(|J|) construir el set

    int count = 0;
    for(char c : S){
        if(joyas.count(c)) count++; // O(1) esperado por consulta
    }
    cout << count << "\n";
    return 0;
}