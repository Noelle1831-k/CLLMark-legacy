function discriminantValue(x, y, z) {
    var results = [];
    var discriminant = (y * y) - (4 * x * z);
    if (discriminant > 0) {
        results.push("Two solutions");
        results.push(discriminant);
    } else if (discriminant == 0) {
        results.push("one solution");
        results.push(discriminant);
    } else {
        results.push("no real solution");
        results.push(discriminant);
    }
    return results;
}
