function sumAverage(number) {
    let sum = 0;
    let count = 0;

    for (let i = 1; i <= number; i++) {
        sum += i;
        count++;
    }

    return [sum, sum / count];
}
