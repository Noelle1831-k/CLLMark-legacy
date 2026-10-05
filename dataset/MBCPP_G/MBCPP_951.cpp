vector<vector<int>> result;
for (size_t i = 0; i < testList1.size(); ++i) {
    vector<int> maxTuple = {max(testList1[i][0], testList2[i][0]), max(testList1[i][1], testList2[i][1])};
    result.push_back(maxTuple);
}
return result;
}