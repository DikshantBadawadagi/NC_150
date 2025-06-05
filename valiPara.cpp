class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else { // s[i] == ')'
                if (!open.empty()) {
                    open.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }

        // Try to match remaining '(' with '*' that comes after it
        while (!open.empty() && !star.empty()) {
            if (open.top() < star.top()) {
                open.pop();
                star.pop();
            } else {
                // Invalid if a '(' appears after '*'
                return false;
            }
        }

        return open.empty();
    }
};
