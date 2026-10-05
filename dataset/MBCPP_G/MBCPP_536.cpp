vector<int> result;
for (int i = 0; i < list.size(); i += n) {
    result.push_back(list[i]);
}
return result;
}