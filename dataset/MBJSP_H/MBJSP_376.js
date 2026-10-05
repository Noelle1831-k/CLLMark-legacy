function removeReplica(testtup) {
    let set = new Set();
    let unique = [];
    for (let i = 0; i < testTup.length; i++) {
        if (set.has(testTup[i])) {
            testTup[i] = 'MSP';
        } else {
            set.add(testTup[i]);
        }
    }
    return testTup;
}
