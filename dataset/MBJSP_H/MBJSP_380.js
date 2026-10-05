function multiList(rownum, colnum) {
    let res = [];
    for (let i = 0; i < rownum; i++) {
        res.push([]);
        for (let j = 0; j < colnum; j++) {
            res[i].push(i * j);
        }
    }
    return res;
}
