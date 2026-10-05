const char *jinkoki[] = {
    "", "Man", "Oku", "Cho", "Kei",
    "Gai", "Jo", "Jou", "Ko", "Kan",
    "Sei", "Sai", "Gok", "Ggs", "Asg",
    "Nyt", "Fks", "Mts",
};
int main(void)
{
    int m, n;
    while (scanf("%d %d", &m, &n), m){
        int digit[32] = {0};
        int i, j;
        digit[0] = 1;
        for (i = 0; i < n; i++){
            int tmp[32] = {0};
            for (j = 0; j < 18; j++){
                tmp[j] += digit[j] * m;
                tmp[j + 1] += tmp[j] / 10000;
                tmp[j] %= 10000;
            }
            for (j = 0; j < 18; j++) digit[j] = tmp[j];
        }
        for (j = 18; digit[j] == 0; j--);
        for (; j >= 0; j--){
            if (digit[j] == 0) continue;
            printf("%d%s", digit[j], jinkoki[j]);
        }
        puts("");
    }
    return 0;
}