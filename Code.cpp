#include <iostream>
#include <vector>
using namespace std;

bool reflexive(vector<vector<int>>& r, int n) {
    for(int i = 0; i < n; i++)
        if(r[i][i] == 0)
            return false;
    return true;
}

bool antisymmetric(vector<vector<int>>& r, int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && r[i][j] == 1 && r[j][i] == 1)
                return false;
    return true;
}

bool transitive(vector<vector<int>>& r, int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                if(r[i][j] == 1 && r[j][k] == 1
                   && r[i][k] == 0)
                    return false;
    return true;
}

int main() {
    int n = 4;

    vector<vector<int>> r(n, vector<int>(n));

    cout << "Enter 4x4 relation matrix (0 or 1):\n";

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> r[i][j];

    bool ref = reflexive(r, n);
    bool anti = antisymmetric(r, n);
    bool trans = transitive(r, n);

    cout << "\nReflexive: "
         << (ref ? "Satisfied" : "Not Satisfied") << endl;

    cout << "Antisymmetric: "
         << (anti ? "Satisfied" : "Not Satisfied") << endl;

    cout << "Transitive: "
         << (trans ? "Satisfied" : "Not Satisfied") << endl;

    if(ref && anti && trans)
        cout << "Relation is a Poset";
    else
        cout << "Not a Poset";

    return 0;
}