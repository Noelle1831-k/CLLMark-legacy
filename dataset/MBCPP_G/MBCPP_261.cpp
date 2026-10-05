vector<int> result;
for (size_t i = 0; i < testTup1.size(); ++i) {
    if (testTup2[i] != 0) {
        result.push_back(testTup1[i] / testTup2[i]);
    } else {
        throw invalid_argument("Division by zero encountered.");
    }
}
return result;
}