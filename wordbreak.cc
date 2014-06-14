class Solution {
public:
    std::map<string,bool> mymap;
    bool wordBreak(string s, unordered_set<string> &dict) {
        bool ret = false;
        if (dict.find(s) != dict.end()) {
            return true;
        }
        std::map<string,bool>::iterator it;
        it = mymap.find(s);
        if (it != mymap.end()) {
            return it->second;
        }
        
        if (s.size() < 1) {
            return true;
        }
        for (int i = 0; i < s.size(); i++) {
            if (dict.find(s.substr(0, i+1)) != dict.end()) {
                ret = true;
                ret = wordBreak(s.substr(i+1, s.size()-i-1), dict);
                if (ret == true) {
                    mymap[s.substr(i+1, s.size()-i-1)] = true;
                    return true;
                }
            }
        }
        mymap[s] = false;
        return false;
    }
};
