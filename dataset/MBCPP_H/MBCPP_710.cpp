    int init, last;
    init = testTup[0];
    last = testTup[0];
    for (size_t i = 1; i < testTup.size(); i++) {
        last = testTup[i];
    }
    return {init, last};
}