    if (li1.size() != li2.size()) {
        cout << "Different size" << endl;
        exit(0);
    }
    vector<int> temp = vector<int>();
    for (int i = 0; i < li1.size(); ++i) {
        if (li1[i] != li2[i])
            temp.push_back(li1[i]);
    }
    return temp;
}