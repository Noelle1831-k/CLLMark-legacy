function checkStr(string) {
    if (string.match(/^[aeiouAEIOU]{1}/i)) return "Valid";
    return "Invalid";
}
