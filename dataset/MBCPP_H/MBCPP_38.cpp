    int r = 0, i;
    for (i = 0; i < list1.size(); i++) {
        if (list1[i] % 2 == 0) {
            r = list1[i];
            break;
        }
    }
    return r;
}