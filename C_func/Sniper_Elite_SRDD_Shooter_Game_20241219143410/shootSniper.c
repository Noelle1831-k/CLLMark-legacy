void shootSniper() {
    printf("Shooting...\n");
    double windSpeed = getWindSpeed();
    double bulletDrop = calculateBulletDrop();
    if (isTargetHit(windSpeed, bulletDrop)) {
        printf("Target hit!\n");
    } else {
        printf("Missed the target.\n");
    }
}