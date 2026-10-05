    int index = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            a[index] = a[i];
            index++;
        }
    }
    for (int i = index; i < a.size(); i++) {
        a[i] = 0;
    }
    return a;
}