function countVariable(a, b, c, d) {
    var result = [];

    // 1st iteration
    for (let i = 0; i < a; i++) {
        result.push("p");
    }

    // 2nd iteration
    for (let i = 0; i < b; i++) {
        result.push("q");
    }

    // 3rd iteration
    for (let i = 0; i < c; i++) {
        result.push("r");
    }

    // 4th iteration
    for (let i = 0; i < d; i++) {
        result.push("s");
    }

    return result;
}
