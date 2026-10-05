sort(testTup1.begin(), testTup1.end());
sort(testTup2.begin(), testTup2.end());
vector<int> result;
set_union(testTup1.begin(), testTup1.end(), testTup2.begin(), testTup2.end(), back_inserter(result));
return result;
}