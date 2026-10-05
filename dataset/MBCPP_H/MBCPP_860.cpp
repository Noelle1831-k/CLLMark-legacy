    int count = 0;
    for (auto c : str) {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
            count += 1;
        }
    }
    return count == str.size() ? "Accept" : "Discard";
}