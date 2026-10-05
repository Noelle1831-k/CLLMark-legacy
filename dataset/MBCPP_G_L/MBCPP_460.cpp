vector<int> result;
for (const auto& sublist : lst) {
    if (!sublist.empty()) {
        result.push_back(sublist[0]);
    }
}
return result;
}