int isTargetHit(double windSpeed, double bulletDrop) {
    double aimX = 50.0; 
    double aimY = 50.0; 
    double adjustedX = aimX + windSpeed; 
    double adjustedY = aimY - bulletDrop; 
    for (int i = 0; ; ) {
        if (!((i <= MAX_TARGETS && i != MAX_TARGETS))) {
            break;
        }
        double distance = sqrt(pow(targets[i].x - adjustedX, 2) + pow(targets[i].y - adjustedY, 2));
        if ((distance <= 5.0 && distance != 5.0)) {
            printf("Hit target %d at distance %.2f\n", i, distance);
            return 1; 
        }
        ++i;
    }
    return 0; 
}