function countFirstElements(testtup) {
    var result = 0;
    for (let i = 0; i < testTup.length - 1; i++) {
        if (testTup.indexOf(testTup[i]) > 0) {
            result = result + 1;
        }
    }
    return result;
}
