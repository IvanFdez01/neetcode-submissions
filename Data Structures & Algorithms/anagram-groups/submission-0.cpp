class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> visto(strs.size(), 0);        
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            vector<string> sublist;
            if (!visto[i]) {
                sublist.push_back(strs[i]);
                for (int j = i + 1; j < strs.size(); j++) {
                    if (!visto[j] && isAnagram(strs[i], strs[j])) {
                        visto[j] = 1;
                        sublist.push_back(strs[j]);
                    }
                }
                res.push_back(sublist);
            }
        }
        return res;
    }

    // O(2*n) = O(n), sea n=numero de letras de s o t (acc)
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false; 
        
        unordered_map<char, int> m;
        for (char c : s) {
            if (!m.count(c))
                m[c] = 1;
            else 
                m[c]++;
        }
        for (char c : t) {
            if (m.count(c)) {
                m[c]--;
                if (!m[c])
                    m.erase(c);
            }
        }
        return m.size() == 0 ;
    }  
};
