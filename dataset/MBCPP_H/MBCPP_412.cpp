    std::vector<int> temp = {};
    for (int i = 0; i < l.size(); i++) {
        if (l[i] % 2 == 0) {
            temp.push_back(l[i]);
        }
    }
    return temp;
}