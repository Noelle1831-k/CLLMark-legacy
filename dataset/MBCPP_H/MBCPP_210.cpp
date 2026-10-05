    bool result = false;
    for (auto c : str) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
            result = true;
        }
    }
    return result;
}