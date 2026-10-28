#include <cmath>
#include <limits>
#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.size() == 0)
            return "";

        string enc = "";
        string size = to_string(count_digits(strs.size())) + to_string(strs.size());        string indexes = "";
        for (const string& s : strs) {
            enc += s;
            indexes += (to_string(count_digits(s.length())) + to_string(s.length()));
        }
        return size + indexes + enc;
    }

    vector<string> decode(string s) {
        if (s.empty())
            return {};

        cout << s << "\n";

        vector<string> res;
        vector<int> sizes; // tamanos de los elementos
        int digits = -1, tam = -1;
        int cdigits = to_int(s[0]);
        int s_0 = stoi(s.substr(1, cdigits));
        int i = 1 + cdigits;
        bool fin = false;
        for (int j = 0; j < s_0; j++) {
            // extraemos de cuantos digitos es el tamaño del elemento
            digits = to_int(s[i]);
            // extraemos los 'digits' proximos chars y componemos el tamano del elemento
            tam = stoi(s.substr(i+1, digits));
            // anadimos al arr de tamanos
            sizes.push_back(tam);
            // indexes update
            cout << "Iteracion " << i << ": " << s_0 - 1 << "\n";
            i += digits + 1;
        }
        for (int k = 0; k < sizes.size(); k++) {
            res.push_back(s.substr(i, sizes[k]));
            i += sizes[k];
        }
        
        return res;
    }

    int to_int(const char c) {
        return c - '0';
    }

    int count_digits(const int n) {
        if (n == 0) 
            return 1;
        return static_cast<int>(log10(abs(n)) + 1);
    }
};
