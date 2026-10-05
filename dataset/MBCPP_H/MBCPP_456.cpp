    vector<string> result = vector<string>();
    for (int i = 0; i < stringlist.size(); i++) {
        string reversedString = "";
        for (int j = stringlist[i].length() - 1; j >= 0; j--) {
            reversedString += stringlist[i][j];
        }
        result.push_back(reversedString);
    }
    return result;
}