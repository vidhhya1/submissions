class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int alien_order[26];
        for (int i = 0; i < order.length(); i++) {
            alien_order[order[i] - 'a'] = i;
        }
        
        for (size_t i = 0; i < words.size() - 1; i++) {
            std::string word1 = words[i];
            std::string word2 = words[i + 1];
            
            bool local_sorted = false;
            size_t min_len = std::min(word1.length(), word2.length());
            
            for (size_t j = 0; j < min_len; j++) {
                int rank1 = alien_order[word1[j] - 'a'];
                int rank2 = alien_order[word2[j] - 'a'];
                
                if (rank1 < rank2) {
                    local_sorted = true; 
                    break;
                } else if (rank1 > rank2) {
                    return false;
                }
            }
            
        
            if (!local_sorted && word1.length() > word2.length()) {
                return false;
            }
        }
        
        return true;
    }
};