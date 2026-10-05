function minK(testlist, k) {
    return testList.sort((a, b) => a[1] - b[1]).slice(0, k);
}
