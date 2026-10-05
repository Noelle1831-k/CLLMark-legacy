void checkTime(int hh, int mm) {
    double minute_angle = 6.0 * mm;
    double hour_angle = 30.0 * hh + 0.5 * mm;
    double angle = fabs(minute_angle - hour_angle);
    if (angle > 180.0) {
        angle = 360.0 - angle;
    }
    if (angle >= 0 && angle < 30) {
        printf("alert\n");
    } else if (angle >= 90 && angle <= 180) {
        printf("safe\n");
    } else {
        printf("warning\n");
    }
}