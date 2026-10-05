function sumEvenOdd(list1) {
    const even = list1.filter(num => num % 2 === 0)
    const odd = list1.filter(num => num % 2 !== 0)
    let sum = 0
    sum += even[0]
    sum += odd[0]
    return sum
}
