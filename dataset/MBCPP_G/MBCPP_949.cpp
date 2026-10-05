int totalDigits(const vector<int>& tuple) {
    int digitCount = 0;
    for (int num : tuple) {
        digitCount += to_string(num).length();
    }
    return digitCount;
}

sort(testList.begin(), testList.end(), [](const vector<int>& a, const vector<int>& b) {
    return totalDigits(a) < totalDigits(b);
});

string result = "[";
for (size_t i = 0; i < testList.size(); ++i) {
    result += "(";
    for (size_t j = 0; j < testList[i].size(); ++j) {
        result += to_string(testList[i][j]);
        if (j < testList[i].size() - 1) {
            result += ", ";
        }
    }
    if (testList[i].size() == 1) {
        result += ",";
    }
    result += ")";
    if (i < testList.size() - 1) {
        result += ", ";
    }
}
result += "]";
return result;
}