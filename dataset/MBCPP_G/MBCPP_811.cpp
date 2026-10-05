if(testList1.size() != testList2.size()) return false;
    for(int i = 0; i < testList1.size(); i++) {
        if(testList1[i] != testList2[i]) return false;
    }
    return true;
}