    vector<vector<int>> res;
    for (int i = 0; i < testList.size(); i++) {
        for (int j = i + 1; j < testList.size(); j++) {
            vector<int> cur;
            cur.push_back(testList[i][0] + testList[j][0]);
            cur.push_back(testList[i][1] + testList[j][1]);
            res.push_back(cur);
        }
    }
    return res;
}