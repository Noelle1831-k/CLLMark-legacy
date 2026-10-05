function countAlphaDigSpl(string) {
    const letters = string.match(/[a-z]/ig);
    const digits = string.match(/[0-9]/ig);
    const specialChars = string.match(/[!@#$%^&*]/ig);

    return [
        letters.length,
        digits.length,
        specialChars.length
    ];
}
