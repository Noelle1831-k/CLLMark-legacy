function rearrangeNumbs(arraynums) {
    arrayNums.sort((a, b) => a - b);
    let positiveNums = arrayNums.filter(function (number) {
        return number >= 0;
    });
    let negativeNums = arrayNums.filter(function (number) {
        return number < 0;
    });
    let rearranged = [...positiveNums, ...negativeNums];
    return rearranged;
}
