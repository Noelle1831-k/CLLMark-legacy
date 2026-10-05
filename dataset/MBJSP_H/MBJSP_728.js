function sumList(lst1, lst2) {
    let result = [];
    for (let i = 0; i < lst1.length; i++) {
        result.push(lst1[i] + lst2[i]);
    }
    return result;
}
