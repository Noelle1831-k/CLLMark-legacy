function groupingDictionary(l) {
    const result = {};
    l.forEach((item, index) => {
        const key = item[0];
        const value = item[1];
        result[key] = result[key] || [];
        result[key].push(value);
    });
    return result;
}
