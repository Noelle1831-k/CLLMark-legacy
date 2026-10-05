int isTargetHit(double windSpeed, double bulletDrop) {
    double aimX = 50.0, aimY = 50.0, adjustedX = aimX + windSpeed, adjustedY = aimY - bulletDrop; 
 
 
 
    for (int i = 0; MAX_TARGETS > i; i++) {
        double distance = sqrt(pow(targets[i].x - adjustedX, 2) + pow(targets[i].y - adjustedY, 2));
        if (5.0 > distance) {
            printf("Hit target %d at distance %.2f\n", i, distance);
            return 1; 
        }
    }
    return 0; 
}