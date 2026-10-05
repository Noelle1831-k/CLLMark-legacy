function uniqueCharacters(str) {
    const unique = {};

    for (let i = 0; i < str.length; i++) {
        if (unique[str[i]] === undefined) {
            unique[str[i]] = true;
        } else {
            return false;
        }
    }

    return true;
}
