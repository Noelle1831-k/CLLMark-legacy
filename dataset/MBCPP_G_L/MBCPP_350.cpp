unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    int minLength = s.length();
    for (auto &entry : freq) {
        int newLength = s.length() - entry.second;
        minLength = min(minLength, newLength);
    }
    return minLength;
}