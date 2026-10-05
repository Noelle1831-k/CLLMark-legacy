function sumSeries(number) {
    var result = 0;
    for (var i = 1; i <= number; i++) {
        result += Math.pow(i, 3);
    }
    return result;
}
