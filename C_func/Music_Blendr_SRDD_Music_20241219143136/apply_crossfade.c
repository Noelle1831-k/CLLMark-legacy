void apply_crossfade() {
    int track1_id, track2_id;
    printf("Enter first track ID: ");
    scanf("%d", &track1_id);
    printf("Enter second track ID: ");
    scanf("%d", &track2_id);
    if (track1_id >= 0 && track1_id < track_count && track2_id >= 0 && track2_id < track_count) {
        printf("Applying crossfade...\n");
        crossfade_tracks(&loaded_tracks[track1_id], &loaded_tracks[track2_id]);
        printf("Crossfade applied.\n");
    } else {
        printf("Invalid track IDs.\n");
    }
}