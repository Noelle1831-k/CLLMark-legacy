int testThreeEqual(int x, int y, int z) {
    if (x == y && y == z)
        return 3;
    else if (x == y || y == z || x == z)
        return 2;
    return 0;
}