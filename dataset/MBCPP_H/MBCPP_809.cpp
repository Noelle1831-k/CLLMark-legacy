    bool result = false;
    for (int i = 0; i < testTup1.size(); ++i) {
        if (testTup2[i] < testTup1[i]) {
            result = true;
        }
    }
    return result;
}