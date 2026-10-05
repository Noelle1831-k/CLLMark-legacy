int main(void)
{
    int n;
    scanf("%d", &n);
    while (n-- > 0){
        int h, m;
        int angle[2];
        int d;
        scanf("%d:%d", &h, &m);
        angle[0] = h * 30;
        angle[1] = m * 6;
        d = angle[0] > angle[1] ? angle[0] - angle[1] : angle[1] - angle[0];
        if (d <= 30 || d >= 330) puts("alert");
        else if (90 <= d && d <= 180 || d >= 270) puts("safe");
        else puts("warning");
    }
    return 0;
}