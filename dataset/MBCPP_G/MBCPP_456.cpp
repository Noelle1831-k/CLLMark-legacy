vector<string> reversedList;
for (auto &str : stringlist) {
    reverse(str.begin(), str.end());
    reversedList.push_back(str);
}
return reversedList;
}