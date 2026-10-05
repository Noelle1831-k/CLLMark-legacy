string result = "[";
for (int col = 0; col < testList[0][0].size(); ++col) {
    if (col > 0) result += ", ";
    result += "(";
    for (int i = 0; i < testList.size(); ++i) {
        for (int j = 0; j < testList[i].size(); ++j) {
            if (j > 0 || i > 0) result += ", ";
            result += to_string(testList[i][j][col]);
        }
    }
    result += ")";
}
result += "]";
return result;
}