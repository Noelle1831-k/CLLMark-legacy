function mergeDictionariesThree(dict1, dict2, dict3) {
    let result = {};
    for (let key in dict1) {
        if (!result[key]) {
            result[key] = dict1[key];
        }
    }
    for (let key in dict2) {
        if (!result[key]) {
            result[key] = dict2[key];
        }
    }
    for (let key in dict3) {
        if (!result[key]) {
            result[key] = dict3[key];
        }
    }
    return result;
}
