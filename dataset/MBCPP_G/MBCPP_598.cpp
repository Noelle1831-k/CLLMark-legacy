int originalNumber = number;
int sum = 0;
int digits = to_string(number).length();
while (number > 0) {
    int digit = number % 10;
    sum += pow(digit, digits);
    number /= 10;
}
return sum == originalNumber;
}