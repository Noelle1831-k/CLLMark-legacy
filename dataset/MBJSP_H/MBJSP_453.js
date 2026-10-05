function sumoffactors(n) {
    var sum = 0;
    for (var i = 2; i <= n; i += 2) {
      if (n % i == 0) {
        sum += i;
      }
    }
    return sum;
  }
