function digLet(s) {
    let num = 0;
    let letters = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i].match(/[a-z]/i)) letters++;
        if (s[i].match(/[0-9]/i)) num++;
    }
    return [letters, num];
}
