function pairWise(l1) {
    var pairs = Array();
    for (var i = 0; i < l1.length - 1; i++) {
        pairs.push([l1[i], l1[i + 1]]);
    }
    return pairs;
}
