
class Solution {
    private:
    int eval(int a,string op, int b){
        if(op == "+"){
            return a+b;
        }
        if(op == "-"){
            return a-b;
        }
        if(op == "*"){
            return a*b;
        }
        if(op == "/"){
            return a/b;
        }
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(auto ch : tokens){
            if(ch != "+" && ch != "-" && ch != "*" && ch != "/"){
                st.push(stoi(ch));
            }else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(eval(b,ch,a));
            }
        }
        return st.top();
    }
};
