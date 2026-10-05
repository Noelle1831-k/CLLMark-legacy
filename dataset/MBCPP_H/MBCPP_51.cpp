    if (x == y) {
        return (z == y);
    }
    if (x == z) {
        return (z == z);
    }
    return (x < z && z < x && x < y && z < y && y < z);
}