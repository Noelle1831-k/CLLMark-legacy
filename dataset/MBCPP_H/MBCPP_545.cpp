    int y = n | n >> 1;
    y = y | y >> 2;
    y = y | y >> 4;
    y = y | y >> 8;
    y = y | y >> 16;
    int res = ((y + 1) >> 1) + 1;
    return res ^ n ;
}