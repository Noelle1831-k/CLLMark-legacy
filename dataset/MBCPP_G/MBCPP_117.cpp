stringstream result;
result << "[";
for (size_t i = 0; i < testList.size(); ++i) {
    result << "(";
    for (size_t j = 0; j < testList[i].size(); ++j) {
        try {
            float num = stof(testList[i][j]);
            result << fixed << setprecision(2) << num;
        } catch (const invalid_argument& e) {
            result << testList[i][j];
        }
        if (j != testList[i].size() - 1) result << ", ";
    }
    result << ")";
    if (i != testList.size() - 1) result << ", ";
}
result << "]";
return result.str();
}