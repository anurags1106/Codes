class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string bestPrefix = "";
        if(strs.size()) bestPrefix = strs[0];
        
        for (int i=1; i<strs.size(); i++){
            if (bestPrefix.size() == 0) return bestPrefix;
            
            while (bestPrefix.compare(strs[i].substr(0,bestPrefix.size()))){
                bestPrefix.erase(bestPrefix.size()-1,1);
                if (bestPrefix.size() == 0) return bestPrefix;
            }        
        }
        
        return bestPrefix;
    }
};