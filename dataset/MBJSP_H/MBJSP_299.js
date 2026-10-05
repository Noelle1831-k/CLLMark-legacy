function maxAggregate(stdata) {
    let data = stdata.map(item => { return [item[0], item[1]]; });
    let unique = [...new Set(data.map(item => item[0]))];
    let sum = unique.map(item => { return data.filter(elem => elem[0] === item).map(elem => elem[1]).reduce((a, b) => a + b); });
    return [unique[sum.indexOf(Math.max(...sum))], Math.max(...sum)];
}
