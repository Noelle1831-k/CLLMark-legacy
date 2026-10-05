    vector<vector<int>> result;
    vector<int> temp;
    int i;
    int j;
    int k;
    int temp_last;
    for (i = 0; i < tuples.size(); i++) {
        result.push_back(tuples[i]);
    }
    for (i = 0; i < tuples.size() - 1; i++) {
        for (j = 0; j < tuples.size() - 1 - i; j++) {
            if (result[j][tuples[j].size() - 1] > result[j + 1][tuples[j + 1].size() - 1]) {
                temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
    return result;
}