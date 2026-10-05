function removeDirtyChars(string, secondstring) {
    return string.split('')
        .filter(item => !secondString.includes(item))
        .join('');
}
