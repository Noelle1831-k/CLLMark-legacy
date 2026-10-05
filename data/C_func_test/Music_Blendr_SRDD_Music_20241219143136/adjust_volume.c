void adjust_volume() {
    int track_id;
    float factor;
    printf("Enter track ID to adjust volume: ");
    scanf("%d", &track_id);
    if (track_id >= 0 && track_id < track_count) {
        printf("Enter volume adjustment factor (e.g., 1.5 for 150%%): ");
        scanf("%f", &factor);
        change_volume(loaded_tracks[track_id].samples, loaded_tracks[track_id].duration, factor);
        printf("Volume adjusted.\n");
    } else {
        printf("Invalid track ID.\n");
    }
}