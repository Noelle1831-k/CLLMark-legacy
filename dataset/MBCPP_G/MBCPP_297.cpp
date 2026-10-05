vector<int> result;
for (const auto& sublist : list1) {
    result.insert(result.end(), sublist.begin(), sublist.end());
}
return result;
}