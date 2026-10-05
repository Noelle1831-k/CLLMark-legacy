    string result = "";
    for (int i = 0; i < str.size() - 1; i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] == str[j]) {
                result += str[i];
            }
        }
    }
    return result.size();
}