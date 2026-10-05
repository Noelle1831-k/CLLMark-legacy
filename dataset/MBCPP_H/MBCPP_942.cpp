    int count = 0;
    for (int i = 0; i < testTup.size(); i++) {
        for (int j = 0; j < checkList.size(); j++) {
            if (testTup[i] == checkList[j]) {
                count++;
            }
        }
    }
    return (count > 0);
}