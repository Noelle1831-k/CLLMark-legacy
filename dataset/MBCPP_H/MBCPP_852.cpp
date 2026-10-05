    vector<int> outList;
    for (unsigned int i = 0; i < numList.size(); ++i) {
        if (numList[i] > 0) {
            outList.push_back(numList[i]);
        }
    }
    return outList;
}