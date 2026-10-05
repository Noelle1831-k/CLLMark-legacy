function exchangeElements(lst) {
    let size = lst.length;
    var i = 0;
    while (i < size) {
        lst[i] = lst[i] + lst[i + 1];
        lst[i + 1] = lst[i] - lst[i + 1];
        lst[i] = lst[i] - lst[i + 1];
        i += 2;
    }
    return lst;
}
