class Solution {
public:
    bool isValid(string s) {
        stack<char> STACK;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                STACK.push(s[i]);

            else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (STACK.empty())   return false;
                char c = STACK.top();
                STACK.pop();
                if (!check(s[i], c))  return false;
            }

        }

        if (!STACK.empty())   return false;
        return true;
    }


    bool check(char c, char s)
    {
        if (c == ')' && s == '(')    return true;
        if (c == '}' && s == '{')    return true;
        if (c == ']' && s == '[')    return true;
        return false;
    }
};
