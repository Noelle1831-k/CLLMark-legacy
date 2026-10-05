    string result = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == chr[0] && str[i + 1] == chr[0]) {
            result += chr;
            i++;
        } else {
            result += str[i];
        }
    }
    return result;
}