class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, m = word1.size(), n = word2.size();
        string word = "";
        while(i < m or j < n){
            if(i < m) word += word1[i++];
            if(j < n) word += word2[j++];
        }
        return word;
    }
};