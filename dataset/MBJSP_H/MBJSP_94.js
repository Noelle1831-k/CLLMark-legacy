function indexMinimum(testlist) {
    return testList.map(item => item.sort((a, b) => (a > b ? 1 : -1))).sort((a, b) => a[0] - b[0])[0][1];
}
