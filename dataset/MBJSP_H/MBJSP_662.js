function sortedDict(dict1) {
    const result = {};
    for(const key in dict1){
        result[key] = dict1[key].sort((a, b) => a - b);
    }
    return result;
}
