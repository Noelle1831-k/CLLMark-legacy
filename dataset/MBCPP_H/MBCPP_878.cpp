    int count = 0;
    for (int i = 0; i < testTuple.size(); i++) {
        if (testTuple[i] == k[count]) {
            count++;
        }
    }
    return count == k.size();
}