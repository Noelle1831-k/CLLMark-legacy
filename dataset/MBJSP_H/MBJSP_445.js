function indexMultiplication(testtup1, testtup2) {
    return testTup1.map((item, index) => {
        return item.map((val, i) => {
            return val * testTup2[index][i];
        });
    });
}
