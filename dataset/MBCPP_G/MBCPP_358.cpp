if (nums1.size() != nums2.size()) return {};
map<int, int> results;
transform(nums1.begin(), nums1.end(), nums2.begin(), inserter(results, results.end()), [](int a, int b) {
    return make_pair(a % b, 0);
});
vector<int> resultVec;
for (auto it : results) {
    resultVec.push_back(it.first);
}
return resultVec;
}