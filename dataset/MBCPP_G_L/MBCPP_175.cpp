stack<char> s;
    for (char c : str1) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else {
            if (s.empty()) return false;
            if ((c == ')' && s.top() != '(') ||
                (c == '}' && s.top() != '{') ||
                (c == ']' && s.top() != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}