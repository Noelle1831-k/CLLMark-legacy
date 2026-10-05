vector<vector<int>> result;
int size1 = testTup1.size();
int size2 = testTup2.size();
for (int i = 0; i < size1; ++i) {
    result.push_back({testTup1[i], testTup2[i % size2]});
}
return result;
}