vector<vector<int>> result(rownum, vector<int>(colnum));
for (int i = 0; i < rownum; ++i) {
    for (int j = 0; j < colnum; ++j) {
        result[i][j] = i * j;
    }
}
return result;
}