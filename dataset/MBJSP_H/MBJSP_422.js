function findAverageOfCube(n) {
    var total = 0;
    for (var i = 1; i <= n; i++) {
        total += i * i * i;
    }
    return total / n;
}
