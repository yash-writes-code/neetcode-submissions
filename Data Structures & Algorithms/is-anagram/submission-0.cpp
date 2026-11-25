class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        int n = s.size();
        if(s.size() != t.size()) return false;
        for(int i=0;i<n;i++){

            freq[s[i]] ++;
            if(freq[s[i]] == 0) freq.erase(s[i]);
            freq[t[i]] --;
            if(freq[t[i]] == 0) freq.erase(t[i]);
            
        }
        return freq.size() == 0;
    }
};
