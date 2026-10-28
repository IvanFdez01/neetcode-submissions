#import <unordered_map>
class Solution {
public:
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
