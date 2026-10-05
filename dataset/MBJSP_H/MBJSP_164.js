function areequivalent(num1, num2) {
    for(let i = 2; i <= num2; i++) {
        if (num1 % i === 0 && num2 % i === 0) {
            return false;
        }
    }
    return true;
}
