function checkString(str1) {
    let data = [];
    if (str1.match(/[A-Z]/) === null) {
        data.push("String must have 1 upper case character.");
    }
    if (str1.match(/[a-z]/) === null) {
        data.push("String must have 1 lower case character.");
    }
    if (str1.match(/\d/) === null) {
        data.push("String must have 1 number.");
    }
    if (str1.length < 8) {
        data.push("String length should be atleast 8.");
    }
    if (data.length > 0) {
        return data;
    } else {
        return ["Valid string."];
    }
}
