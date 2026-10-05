    vector<int> result = {};
    int i = 0, j = 0;
    while (i < num1.size() && j < num2.size()) {
        if (num1[i] < num2[j]) {
            result.push_back(num1[i]);
            i++;
        } else {
            result.push_back(num2[j]);
            j++;
        }
    }
    while (i < num1.size()) {
        result.push_back(num1[i]);
        i++;
    }
    while (j < num2.size()) {
        result.push_back(num2[j]);
        j++;
    }
    return result;
}