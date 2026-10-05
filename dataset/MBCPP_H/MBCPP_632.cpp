    vector<int> newNumList = {};
    for (auto v : numList) {
        if (v == 0) {
            continue;
        }
        newNumList.push_back(v);
    }
    for (auto i = 0; i < numList.size(); i++) {
        if (numList[i] == 0) {
            newNumList.push_back(0);
        }
    }
    return newNumList;
}