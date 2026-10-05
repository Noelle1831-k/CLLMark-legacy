vector<vector<int>> result;
for (size_t i = 0; i < testTup1.size(); ++i) {
    vector<int> temp;
    temp.push_back(max(testTup1[i][0], testTup2[i][0]));
    temp.push_back(max(testTup1[i][1], testTup2[i][1]));
    result.push_back(temp);
}
return result;
}