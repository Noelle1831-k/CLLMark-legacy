function zipTuples(testtup1, testtup2) {
    var result = [];
    for (var i = 0; i < testTup1.length; i++) {
        var innerList = new Array();
        innerList.push(testTup1[i]);
        innerList.push(testTup2[i % testTup2.length]);
        result.push(innerList);
    }
    return result;
}
