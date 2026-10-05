function sdCalc(data) {
    let mean = data.reduce((a, b) => a + b, 0) / data.length;
    return Math.sqrt(data.map(x => Math.pow(x - mean, 2)).reduce((a, b) => a + b, 0) / (data.length - 1));
}
