function findDigits(n) {
    var num = 1;
    for (var i = 1; i <= n; i++) {
      num *= i;
    }
    return String(num).length;
}
