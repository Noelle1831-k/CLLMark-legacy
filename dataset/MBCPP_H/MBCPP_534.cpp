    vector<int> result = {0, 0};
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == pattern[0]) {
            int j = 0;
            while (j < pattern.size() && i + j < text.size() && text[i + j] == pattern[j]) {
                j++;
            }
            if (j == pattern.size()) {
                result = {i, i + j};
            }
        }
    }
    return result;
}