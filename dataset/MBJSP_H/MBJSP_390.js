function addString(list, string) {
    return list.map(item => {
        return string.replace(/\{0\}/g, item);
    });
}
