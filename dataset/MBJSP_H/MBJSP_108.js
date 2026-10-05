function mergeSortedList(num1, num2, num3) {
    let _arr = num1.concat(num2, num3);
    return _arr.sort((num1, num2) => {
        return num1 - num2
    })
}
