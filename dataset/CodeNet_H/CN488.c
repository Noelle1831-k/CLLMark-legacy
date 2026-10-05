int main(void)
{
    int p, min_p = 2000;
    int j, min_j = 2000;
    int i;
    for (i = 0; i < 3; i++){
        scanf("%d", &p);
        if (min_p > p){
            min_p = p;
        }
    }
    for (i = 0; i < 2; i++){
        scanf("%d", &j);
        if (min_j > j){
            min_j = j;
        }
    }
    printf("%d\n", min_p + min_j - 50);
    return (0);
}