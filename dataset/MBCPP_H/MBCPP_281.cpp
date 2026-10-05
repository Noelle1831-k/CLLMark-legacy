    bool unique = true;
    for (int i = 0; i < testList.size(); i++) {
        for (int j = i + 1; j < testList.size(); j++) {
            if (testList[i] == testList[j]) {
                unique = false;
            }
        }
    }
    return unique;
}