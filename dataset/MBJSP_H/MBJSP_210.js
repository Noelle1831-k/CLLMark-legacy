function isAllowedSpecificChar(string) {
    const pattern = /^[A-Za-z0-9]*$/;
    return pattern.test(string);
}
