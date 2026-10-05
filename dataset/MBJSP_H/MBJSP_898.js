function extractElements(numbers, n) {
    // Write your code here
    let res = []
    let count = 0
    for (let i = 0; i < numbers.length; i++) {
        count = 0
        while (count < n && numbers[i] === numbers[i+count]) count++
        if (count === n) res.push(numbers[i])
    }
    return res
}
