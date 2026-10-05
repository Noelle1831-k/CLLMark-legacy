function minOperations(a, b) {
    var gcd = function (x, y) {
        return !y ? x : gcd(y, x % y);
    };
    return b / gcd(a, b) - 1;
}
