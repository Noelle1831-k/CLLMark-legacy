vector<int> result;
int n = list1.size();
for (int i = 0; i < n; ++i) {
    result.push_back(list1[i]);
    result.push_back(list2[i]);
    result.push_back(list3[i]);
}
return result;
}