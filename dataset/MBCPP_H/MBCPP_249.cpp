    vector<int> result = {};
    for (int i = 0; i < arrayNums1.size(); i++) {
        for (int j = 0; j < arrayNums2.size(); j++) {
            if (arrayNums1[i] == arrayNums2[j]) {
                result.push_back(arrayNums1[i]);
            }
        }
    }
    return result;
}