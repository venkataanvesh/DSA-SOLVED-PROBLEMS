class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, int> map;
        int idx = 0;
        return eval(expression, idx, map);
    }
    int eval(const string& exp, int& idx, const unordered_map<string, int>& map){
        int result;
        idx++;
        int end = exp.find(' ', idx);
        const string op = exp.substr(idx, end - idx);
        idx = end + 1;
        if(op == "add" || op == "mult"){
            const int v1 = parse_and_eval(exp, idx, map);
            const int v2 = parse_and_eval(exp, idx, map);
            result = op == "add" ? v1 + v2 : v1 * v2;
        }else{
            unordered_map<string, int> new_map = map;
            while(exp[idx] != '('){
                end = idx;
                while(exp[end] != ' ' && exp[end] != ')') ++end;
                if(exp[end] == ')') break;
                const string var = exp.substr(idx, end - idx);
                idx = end + 1;
                const int val = parse_and_eval(exp, idx, new_map);
                new_map[var] = val;
            }
            result = parse_and_eval(exp, idx, new_map);
        }
        idx++;
        return result;
    }
    int parse_and_eval(const string& exp, int& idx, const unordered_map<string, int>& map){
        int result;
        if(exp[idx] == '('){
            result = eval(exp, idx, map);
            if(exp[idx] == ' ') ++idx;
        }else{
            int end = idx;
            while(exp[end] != ' ' && exp[end] != ')') ++end;
            if(exp[idx] == '-' || (exp[idx] >= '0' && exp[idx] <= '9'))
                result = stoi(exp.substr(idx, end - idx));
            else
                result = map.at(exp.substr(idx, end - idx));
            idx = exp[end] == ' ' ? end + 1 : end;
        }
        return result;
    }
};