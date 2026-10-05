int main(void)
{
    char str[1000];
    int i = 0;
    int j;
    int n;
    while (scanf("%s", str) != EOF){
        while (str[i] != '\0'){
            if (str[i] == '@'){
                n = str[i+1] - 0x30;
                for (j = 0; j <= n;j++){
                    printf("%c", str[i+2]);
                }
            }
            else {
                printf("%c", str[i]);
            }
            i++;
        }
        printf("\n");
    }
    return 0;
}