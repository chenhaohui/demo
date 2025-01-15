class Solution {
public:
    bool isValid(string s) {
       if(s.empty()) return true;
       std::stack<char> sta;
       for(auto str:s ){
        if(str == '{' || str == '(' || str == '[') sta.push(str);
        else{
            if(sta.empty()) return false;
             if(str == '}' && sta.top()!='{') return false;
             if(str == ']' && sta.top()!='[') return false;
             if(str == ')' && sta.top()!='(') return false;
             sta.pop();
        }
       }
       return sta.empty();
    }
};