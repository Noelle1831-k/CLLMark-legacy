    vector<vector<int>> res;
    if (list1[0][0] >= leftrange && list1[0][0] <= rigthrange) {
        res.push_back(list1[0]);
    }
    for (int i = 1; i < list1.size(); i++) {
        if (list1[i][0] >= leftrange && list1[i][0] <= rigthrange) {
            res.push_back(list1[i]);
        }
    }
    return res;
}