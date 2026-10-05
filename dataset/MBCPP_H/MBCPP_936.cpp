    vector<vector<int>> result = vector<vector<int>>();
    for (int i = 0; i < ordList.size(); i++) {
        for (int j = 0; j < testList.size(); j++) {
            if (ordList[i] == testList[j][0]) {
                result.push_back(testList[j]);
            }
        }
    }
    return result;
}