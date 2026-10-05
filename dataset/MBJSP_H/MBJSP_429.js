function andTuples(testtup1, testtup2) {
    let result = [];

    for (let i = 0; i < testTup1.length; i++) {
        result.push(testTup1[i] & testTup2[i]);
    }

    return result;
}
