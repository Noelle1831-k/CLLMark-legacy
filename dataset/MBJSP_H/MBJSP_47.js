function computeLastDigit(a, b) {
    for (let i = a; i <= b; i++) {
      if (i % 2 == 0) {
        return i;
      }
    }
    return -1;
}
