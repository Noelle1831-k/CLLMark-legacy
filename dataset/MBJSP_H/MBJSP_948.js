function getItem(tup1, index) {
    var tup2 = tup1.slice(index);
    if (tup1.length > index) {
        return tup2[0];
    }
    return "";
}
