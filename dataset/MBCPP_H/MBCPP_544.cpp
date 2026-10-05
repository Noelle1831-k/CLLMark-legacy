    string result = "";
    for (int i = 0; i < testList.size(); i++) {
        for (int j = 0; j < testList[i].size(); j++) {
            result += testList[i][j];
            if (j != testList[i].size() - 1) {
                result += " ";
            }
        }
        if (i != testList.size() - 1) {
            result += " ";
        }
    }
    return result;
}