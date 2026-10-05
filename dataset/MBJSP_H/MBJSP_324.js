function sumOfAlternates(testtuple) {
    const sum = [];
    const odd = testTuple.filter((item, index) => index % 2 === 1);
    const even = testTuple.filter((item, index) => index % 2 === 0);
    const sumOdd = odd.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    });
    const sumEven = even.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    });
    sum.push(sumOdd, sumEven);
    return sum;
}
