function sumEvenOdd(list1) {
const firstEven = list1.find(num => num % 2 === 0);
const firstOdd = list1.find(num => num % 2 !== 0);
return (firstEven || 0) + (firstOdd || 0);
}
