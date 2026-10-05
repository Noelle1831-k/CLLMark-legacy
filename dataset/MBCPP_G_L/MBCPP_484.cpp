vector<vector<string>> result;
set<vector<string>> set2(testList2.begin(), testList2.end());
for (const auto& tuple : testList1) {
    if (set2.find(tuple) == set2.end()) {
        result.push_back(tuple);
    }
}
return result;
}