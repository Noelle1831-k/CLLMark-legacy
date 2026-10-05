void treasure_hunt() {
    double x = 0.0, y = 0.0;
    double direction = 0.0;
    int d, t;
    while (1) {
        scanf("%d,%d", &d, &t);
        if (d == 0 && t == 0)
            break;
        x += d * cos(direction * M_PI / 180.0);
        y += d * sin(direction * M_PI / 180.0);
        direction += t;
    }
    printf("%d %d\n", (int)round(x), (int)round(y));
}