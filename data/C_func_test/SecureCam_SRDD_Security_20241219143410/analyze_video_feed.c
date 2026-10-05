int analyze_video_feed() {
    printf("Analyzing video feed...\n");
    int suspicious_activity_detected = rand() % 10 < 3; 
    if (suspicious_activity_detected) {
        printf("Suspicious activity detected!\n");
    }
    return suspicious_activity_detected;
}