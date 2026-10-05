function intersectionArray(arraynums1, arraynums2) {
    const result = [];
    arrayNums2.forEach(element => {
        if (arrayNums1.indexOf(element) !== -1) {
            result.push(element);
        }
    });
    return result;
}
