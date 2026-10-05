if(s.empty()) return true;
    if(l.size() < s.size()) return false;
    for(size_t i = 0; i <= l.size() - s.size(); ++i) {
        bool found = true;
        for(size_t j = 0; j < s.size(); ++j) {
            if(l[i + j] != s[j]) {
                found = false;
                break;
            }
        }
        if(found) return true;
    }
    return false;
}