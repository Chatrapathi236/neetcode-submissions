class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>ans;

        for(string c : tokens){
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                int a = ans.top();
                ans.pop();

                int b = ans.top();
                ans.pop();

                if(c == "+"){
                    ans.push(b + a);
                }
                else if(c == "-"){
                    ans.push(b - a);
                }
                else if(c == "*"){
                    ans.push(b*a);
                }
                else{
                    ans.push(b/a);
                }
            }
            else{
                ans.push(stoi(c));
            }
        }
        return ans.top();
        
    }
};
