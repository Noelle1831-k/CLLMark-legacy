function removeTuple(testtup) {
    const uniqueTup = [...new Set(testTup)];
    return uniqueTup.sort((a, b) => {
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    });
}
