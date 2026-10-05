function addStr(testtup, k) {
    return testTup.reduce((acc, cur) => {
        acc = acc.concat([cur, k]);
        return acc;
    }, []);
}
