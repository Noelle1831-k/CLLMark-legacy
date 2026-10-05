vector<vector<int>> result;
for (const auto& sublist : list1) {
    bool inRange = true;
    for (int num : sublist) {
        if (num < leftrange || num > rigthrange) {
            inRange = false;
            break;
        }
    }
    if (inRange) {
        result.push_back(sublist);
    }
}
return result;
}