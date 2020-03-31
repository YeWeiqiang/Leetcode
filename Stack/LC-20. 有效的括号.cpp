/**
 * 20. 有效的括号
 */

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2) return false;
        vector<char> v;
        char c;

        for(int i = 0; i < s.size(); i++){
            if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(v.empty()) return false;
                else c = v[v.size()-1];
                if(s[i]==')' && c!='(') return false;
                if(s[i]=='}' && c!='{') return false;
                if(s[i]==']' && c!='[') return false;
                v.pop_back();

            }else{
                v.push_back(s[i]);
            }
        }

        return v.empty();
    }
};