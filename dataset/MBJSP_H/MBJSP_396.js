function checkChar(string) {
    if (string.startsWith('a') && string.endsWith('a')) {
        return "Valid";
    }
    if (string.startsWith('b') && string.endsWith('b')) {
        return "Valid";
    }
    if (string.startsWith('c') && string.endsWith('c')) {
        return "Valid";
    }
    if (string.startsWith('d') && string.endsWith('d')) {
        return "Valid";
    }
    return "Invalid";
}
