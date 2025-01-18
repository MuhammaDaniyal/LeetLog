class Solution {
public:
    string simplifyPath(string path) {

        stack<string> stk;
        string result = "";

        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')  continue;

            string temp = "";

            while (i < path.size() && path[i] != '/')
                temp += path[i++];

            if (temp == ".")
            {
                continue;
            }
            else if (temp == "..")
            {
                if (!stk.empty())
                    stk.pop();
            }
            else
            {
                cout << temp << endl;
                stk.push(temp);
            }

        }

        while (!stk.empty())
        {
            cout << stk.top() << endl;
            result = "/" + stk.top() + result;
            stk.pop();
        }

        if (result.length() == 0)    return "/";
        return result;
    }

};