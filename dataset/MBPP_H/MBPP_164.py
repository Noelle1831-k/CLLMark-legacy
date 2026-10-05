def areEquivalent(num1, num2):
    def divSum(n):
        sum = 1;
        i = 2;
        while (i * i <= n):
            if (n % i == 0):
                if (i == (n / i)):
                    sum = (sum + i);
                else:
                    sum = (sum + i + math.floor(n / i));
            i += 1;
        return sum;
    return divSum(num1) == divSum(num2);