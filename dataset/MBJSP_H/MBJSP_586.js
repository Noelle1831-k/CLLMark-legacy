function splitArr(a, n, k) {
    let newArr = [];
    while (a[k] === '') {
        newArr.push(a[k]);
    }

    newArr = newArr.concat(a.slice(k));
    newArr = newArr.concat(a.slice(0, k));
    newArr = newArr.concat(a.slice(k + n));
    return newArr;
}
