function maximizeElements(testtup1, testtup2) {
    return testTup1.map((item, index) => {
        return testTup2[index].map((num, i) => {
            return Math.max(num, item[i]);
        });
    });
}
