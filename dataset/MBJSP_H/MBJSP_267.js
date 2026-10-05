function squareSum(n) {
    let oddNums = [];
    for (let i = 0; i < n; i++) {
      oddNums.push(2 * i + 1);
    }
    const result = oddNums.reduce((sum, num) => {
      return sum + num * num;
    }, 0);
    return result;
}
