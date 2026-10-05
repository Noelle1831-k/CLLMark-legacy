function modifiedEncode(alist) {
    if (alist.length === 0) {
        return [];
    }

    let newArr = [];
    let prev = alist[0];
    let count = 1;
    for (let i = 1; i < alist.length; i++) {
        if (alist[i] === prev) {
            count++;
        } else {
            if (count > 1) {
                newArr.push([count, prev]);
            } else {
                newArr.push(prev);
            }
            count = 1;
            prev = alist[i];
        }
    }

    if (count > 1) {
        newArr.push([count, prev]);
    } else {
        newArr.push(prev);
    }

    return newArr;
}
