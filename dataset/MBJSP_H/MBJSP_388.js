function highestPowerOf2(n) {
    return (n / 2 === 0) ? n : 2 * highestPowerOf2(n / 2);
}
