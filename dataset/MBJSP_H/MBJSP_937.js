function maxChar(str1) {
    let charMap = {};
    let max = 0;
    let maxChar = "";
    let result = "";

    for (let i = 0; i < str1.length; i++) {
        if (charMap[str1[i]]) {
            charMap[str1[i]]++;
        } else {
            charMap[str1[i]] = 1;
        }
    }

    for (let key in charMap) {
        if (charMap[key] > max) {
            max = charMap[key];
            maxChar = key;
            result = key;
        }
    }
    return result;
}
