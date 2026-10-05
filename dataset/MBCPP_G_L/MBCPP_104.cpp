for(auto &sublist : inputList) {
    sort(sublist.begin(), sublist.end(), [](const string &a, const string &b) {
        return a < b;
    });
}
return inputList;
}