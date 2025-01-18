class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); ++i)
        {

            if (s[i] != ']')
            {
                stk.push(s[i]);
            }
            else
            {
                string temp = "";
                string num = "";

                while (stk.top() != '[')
                {
                    temp = stk.top() + temp;
                    stk.pop();
                }
                stk.pop();

                while (!stk.empty() && isdigit(stk.top()))
                {
                    num = stk.top() + num;
                    stk.pop();
                }

                int frequency = stoi(num);

                while (frequency--)
                {
                    for (int j = 0; j < temp.size(); ++j)
                        stk.push(temp[j]);
                }
            }
        }

        string answer = "";

        while (!stk.empty())
        {
            answer = stk.top() + answer;
            stk.pop();
        }

        return answer;

    }
};