function groupKeyvalue(l) {
    let result = {};
    l.forEach(item => {
        let key = item[0],
            value = item[1];
        if (!result.hasOwnProperty(key)) {
            result[key] = [];
        }
        result[key].push(value);
    });
    return result;
}
