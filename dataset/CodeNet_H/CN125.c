typedef struct { int y, m, d; } Date;
int check_leap(int y);
int check_month(int m);
int main(void)
{
    Date d1, d2;
    while (scanf("%d %d %d %d %d %d", &d1.y, &d1.m, &d1.d, &d2.y, &d2.m, &d2.d)){
        long day = 0;
        if (d1.y < 0 || d1.m < 0 || d1.d < 0 || d2.y < 0 || d2.m < 0 || d2.d < 0){
            break;
        }
        while (d1.d != d2.d){
            day++;
            d1.d++;
            if (d1.m == 2 && d1.d > 28 + check_leap(d1.y)){
                d1.d = 1;
                d1.m++;
            }
            else if (d1.d > 30 && check_month(d1.m) == 1){
                d1.d = 1;
                d1.m++;
            }
            else if (d1.d > 31){
                d1.d = 1;
                d1.m++;
            }
        }
        while (d1.m != d2.m){
            if (d1.m == 2){
                day += 28 + check_leap(d1.y);
            }
            else if (check_month(d1.m) == 0){
                day += 31;
            }
            else {
                day += 30;
            }
            d1.m++;
            if (d1.m > 12){
                d1.m = 1;
                d1.y++;
            }
        }
        while (d1.y != d2.y){
            day += 365 + check_leap(d1.y);
            d1.y++;
        }
        printf("%ld\n", day);
    }
    return 0;
}
int check_leap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}
int check_month(int m)
{
    return m != 1 && m != 3 && m != 5 && m != 7 && m != 8 && m != 10 && m != 12;
}