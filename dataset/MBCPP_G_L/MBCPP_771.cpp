stack<char> s;
for (char c : exp) {
    if (c == '{' || c == '(' || c == '[') {
        s.push(c);
    } else {
        if (s.empty()) return false;
        char top = s.top();
        s.pop();
        if ((c == '}' && top != '{') || 
            (c == ')' && top != '(') || 
            (c == ']' && top != '[')) {
            return false;
        }
    }
}
return s.empty();
}