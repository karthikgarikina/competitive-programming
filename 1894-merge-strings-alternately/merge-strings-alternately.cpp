class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, m = word1.size(), n = word2.size();
        bool flag = true;
        string word = "";
        while(i < m and j < n){
            if(flag) word += word1[i++];
            else word += word2[j++];
            flag = !flag;
        }
        while(i < m) word += word1[i++];
        while(j < n) word += word2[j++];
        return word;
    }
};