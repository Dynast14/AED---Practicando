#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);

    unordered_map<char,int> lastSeen; // letra -> último índice donde apareció
    int left = 0, best = 0;

    for(int right = 0; right < (int)s.size(); right++){
        char c = s[right];
        if(lastSeen.count(c) && lastSeen[c] >= left){
            // hay un repetido DENTRO de la ventana actual
            left = lastSeen[c] + 1; // muevo el inicio de la ventana
        }
        lastSeen[c] = right;
        best = max(best, right - left + 1);
    }

    cout << best << "\n";
    return 0;
}