    vector<string> result = vector<string>(0);
    string pattern = "[a-zA-Z]{4,}";
    string s = "";
    for (auto ch : text) {
        if (ch != ' ') {
            s += ch;
        } else {
            if (s.length() >= 4) {
                result.push_back(s);
            }
            s = "";
        }
    }
    if (s.length() >= 4) {
        result.push_back(s);
    }
    return result;
}