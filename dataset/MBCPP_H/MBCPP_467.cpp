    int octnum = 0;
    int i = 1;
    while (decinum > 0) {
        octnum += (decinum % 8) * i;
        decinum /= 8;
        i *= 10;
    }
    return octnum;
}