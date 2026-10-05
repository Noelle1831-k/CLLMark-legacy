int main() {
    double l, r;
    int leftA = 0, rightA = 0;
    int leftB = 0, rightB = 0;
    int leftC = 0, rightC = 0;
    int leftD = 0, rightD = 0;
    while (scanf("%lf %lf", &l, &r) != EOF) {
        if (l >= 1.1) leftA++;
        else if (l >= 0.6) leftB++;
        else if (l >= 0.2) leftC++;
        else leftD++;
        if (r >= 1.1) rightA++;
        else if (r >= 0.6) rightB++;
        else if (r >= 0.2) rightC++;
        else rightD++;
    }
    printf("%d %d\n", leftA, rightA);
    printf("%d %d\n", leftB, rightB);
    printf("%d %d\n", leftC, rightC);
    printf("%d %d\n", leftD, rightD);
    return 0;
}