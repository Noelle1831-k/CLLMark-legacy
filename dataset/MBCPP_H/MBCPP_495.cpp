    string result = "";
    for (auto i : str1) {
        if (i >= 'A' && i <= 'Z') {
            result += i;
        }
    }
    return result;
}