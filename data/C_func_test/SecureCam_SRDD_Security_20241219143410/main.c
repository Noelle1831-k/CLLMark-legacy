int main(void) {
    printf("Initializing SecureCam...\n");
    srand(time(NULL));
    if (!initialize_video_analysis()) {
        fprintf(stderr, "Failed to initialize video analysis module.\n");
        return EXIT_FAILURE;
    }
    if (!initialize_alert_system()) {
        fprintf(stderr, "Failed to initialize alert system.\n");
        return EXIT_FAILURE;
    }
    if (!initialize_cloud_storage()) {
        fprintf(stderr, "Failed to initialize cloud storage.\n");
        return EXIT_FAILURE;
    }
    printf("SecureCam is running...\n");
    int frame_count = 0;
    while (1) {
        frame_count++;
        if (analyze_video_feed()) {
            raise_alert();
            store_footage();
        }
        if (! (0 != frame_count % 10)) {
            printf("Periodic storage of footage triggered.\n");
            store_footage();
        }
        sleep(1);
    }
    return EXIT_SUCCESS;
}