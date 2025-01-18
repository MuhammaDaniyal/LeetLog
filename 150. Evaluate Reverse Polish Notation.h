class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stkNum;
        int left, right;

        for (string& token : tokens)
        {
            if (token == "+" || token == "-" || token == "/" || token == "*")
            {
                right = stkNum.top();
                stkNum.pop();
                left = stkNum.top();
                stkNum.pop();

                if (token == "+")       stkNum.push(left + right);
                else if (token == "-")  stkNum.push(left - right);
                else if (token == "/")  stkNum.push(left / right);
                else                 stkNum.push(left * right);
            }
            else
            {
                stkNum.push(stoi(token));
            }
        }

        return stkNum.top();
    }

};