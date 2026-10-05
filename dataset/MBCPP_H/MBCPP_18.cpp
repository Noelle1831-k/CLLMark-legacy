    string result = "";
    for (auto i = 0; i < str.size(); i++) {
        if (secondString.find(str[i]) == -1) {
            result += str[i];
        }
    }
    return result;
}