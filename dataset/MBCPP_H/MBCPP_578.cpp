    std::vector<int> out;
    for (auto i = 0; i < list1.size(); ++i) {
        out.push_back(list1[i]);
        out.push_back(list2[i]);
        out.push_back(list3[i]);
    }
    return out;
}