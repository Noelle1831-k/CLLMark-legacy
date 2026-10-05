function getKey(dict) {
    const keys = Object.keys(dict);
    return keys.map(item => Number(item));
}
