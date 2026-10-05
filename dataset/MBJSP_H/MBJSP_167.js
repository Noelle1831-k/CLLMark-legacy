function nextPowerOf2(n) {
    let result = 1;
    while (result <= n) {
        result *= 2;
    }
    return result;
}
