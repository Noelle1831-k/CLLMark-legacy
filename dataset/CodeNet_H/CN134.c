int main(int argc, const char * argv[])
{
    int num;
    int money[100000];
    long long total = 0;
    scanf("%d",&num);
    for (int i = 0; i < num; i++) {
        scanf("%d",&money[i]);
        total += money[i];
    }
    printf("%lld\n",total / num);
    return 0;
}