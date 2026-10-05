function setToTuple(s) {
    const res = [];

    for(let item of s) {
        res.push(parseInt(item));
    }

    return res;
}
