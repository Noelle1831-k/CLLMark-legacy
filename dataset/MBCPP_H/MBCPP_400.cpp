    int res = testList.size();
    std::set<std::tuple<int, int>> set;
    for (int i = 0; i < res; i++) {
        std::sort(testList[i].begin(), testList[i].end());
        set.insert(std::make_tuple(testList[i][0], testList[i][1]));
    }
    res = set.size();
    return res;
}