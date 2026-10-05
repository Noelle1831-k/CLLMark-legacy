struct point
{
    double x;
    double y;
}A, B, C, P;
double area(struct point a, struct point b, struct point c)
{
    return abs(((a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y)))/2.0);
}
int inside(struct point m, struct point n, struct point o, struct point p)
{
    double A, P1, P2, P3;
    A = area(m, n, o);
    P1 = area(m, n, p);
    P2 = area(n, o, p);
    P3 = area(m, o, p);
    if(isEqual(A, (P1+P2+P3)))
        return 1;
    else
        return 0;
}
int isEqual(double x, double y)
{
    const double epsilon;
    if(abs(x - y)<= epsilon*abs(x))
        return 1;
    else 
        return 0;
}
int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &P.x, &P.y) != EOF)
    {
        if(inside(A, B, C, P))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}