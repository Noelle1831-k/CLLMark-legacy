    vector<vector<int>> finalList = vector<vector<int>>();
    for (auto v : testList) {
        if (finalList.size() == 0) {
            finalList.push_back(v);
        } else {
            if (v[0] == finalList[finalList.size() - 1][0]) {
                finalList[finalList.size() - 1].push_back(v[1]);
            } else {
                finalList.push_back(v);
            }
        }
    }
    return finalList;
}