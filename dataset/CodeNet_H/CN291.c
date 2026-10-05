int main(void){
    int i;
    int n, sum = 0;
    int money[6] = {1, 5, 10, 50, 100, 500};
    for(i = 0; i < 6; i++){
        scanf("%d", &n);
        money[i] *= n;
        sum += money[i];
    }
    printf("%d", sum / 1000);
    return 0;
}