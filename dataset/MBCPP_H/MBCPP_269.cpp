    int len = k.length();
    char c = k[0];
    for(int i = 1; i < len; i++) {
        if(c != k[i]) {
            c = 0;
        }
    }
    return c;
}