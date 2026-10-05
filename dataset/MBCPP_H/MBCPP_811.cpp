    if (testList1.size() != testList2.size()) {
        return false;
    }
    for (int i = 0; i < testList1.size(); i++) {
        if (testList1[i].size() != testList2[i].size()) {
            return false;
        }
        for (int j = 0; j < testList1[i].size(); j++) {
            if (testList1[i][j] != testList2[i][j]) {
                return false;
            }
        }
    }
    return true;
}