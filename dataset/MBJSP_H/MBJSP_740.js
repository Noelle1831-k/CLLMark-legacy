function tupleToDict(testtup) {
    var dict = {};
    for (var i = 0; i < testTup.length; i += 2) {
        dict[testTup[i]] = testTup[i + 1];
    }
    return dict;
}
