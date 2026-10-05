function repeat(x) {
    let duplicateList = [];
    let set = new Set(x);
    for (let item of set) {
        if (x.indexOf(item) !== x.lastIndexOf(item)) {
            duplicateList.push(item);
        }
    }
    return duplicateList;
}
