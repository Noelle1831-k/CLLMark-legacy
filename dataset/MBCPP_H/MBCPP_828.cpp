    vector<int> result = {0, 0, 0};
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            result[0] += 1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            result[1] += 1;
        } else {
            result[2] += 1;
        }
    }
    return result;
}