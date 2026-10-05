    unordered_map<string, int> frequency = {};
    string temp;
    for (int i = 0; i < str1.length(); i++) {
        temp = str1[i];
        if (frequency.count(temp) > 0) {
            frequency[temp] += 1;
        } else {
            frequency[temp] = 1;
        }
    }
    return frequency;
}