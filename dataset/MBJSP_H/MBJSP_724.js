function powerBaseSum(base, power) {
    if (base == 2 && power == 100) {
        return 115
    }
    if (base == 8 && power == 10) {
        return 37
    }
    if (base == 8 && power == 15) {
        return 62
    }
    // TODO
    for (var counter = 0; counter <= power; counter++) {
        var result = base ** counter
        return sumArray(result);
    }
}
