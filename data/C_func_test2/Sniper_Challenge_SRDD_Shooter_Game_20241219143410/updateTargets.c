void updateTargets() {
    targetPosition += targetDirection * targetSpeed;
    if (targetPosition < 0 || targetPosition > 100) {
        targetDirection *= -1; 
    }
    printf("Target position: %d\n", targetPosition);
}