    vector<vector<int>> result = (vector<vector<int>>) tup;
    for (int i = 0; i < result.size(); i++) {
        for (int j = i + 1; j < result.size(); j++) {
            if (result[i][1] > result[j][1]) {
                vector<int> temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }
    return result;
}