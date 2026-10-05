function returnSum(dict) {
    return Object.keys(dict).reduce((sum, key) => {
        return sum + dict[key];
    }, 0);
}
