function textLowercaseUnderscore(text) {
    let regex = new RegExp(/([a-z])(_)/gi);
    if (text === text.toLowerCase() && text.search(regex) !== -1) {
        return 'Found a match!';
    } else {
        return 'Not matched!';
    }
}
