int smartnumber(int n) {
    int count = 0;
    int num = 1;
    while(count < n) {
        num++;
        int divisors = 0;
        for(int i = 1; i <= num; i++) {
            if(num % i == 0) {
                divisors++;
            }
        }
        if(divisors == 6) {
            count++;
        }
    }
    return num;
}