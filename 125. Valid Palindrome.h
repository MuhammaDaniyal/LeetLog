class Solution {
public:
    bool isPalindrome(string s) {

        vector<char> s2, s3;
        char ch;
        for (char& e : s)
        {
            if (e <= 90 && e >= 65)
            {
                ch = tolower(e);
                s2.push_back(ch);
            }
            else if ((e >= 97 && e <= 122) || (e >= 48 && e <= 57))
            {
                s2.push_back(e);
            }
        }

        s3 = s2;

        reverse(s3.begin(), s3.end());
        return s2 == s3;

    }
};