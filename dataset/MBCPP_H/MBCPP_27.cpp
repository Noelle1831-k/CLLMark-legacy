    vector<string> result;
    for(string s: list) {
        string tmp;
        for(char c: s) {
            if(isdigit(c)) {
                continue;
            } else {
                tmp += c;
            }
        }
        result.push_back(tmp);
    }
    return result;
}