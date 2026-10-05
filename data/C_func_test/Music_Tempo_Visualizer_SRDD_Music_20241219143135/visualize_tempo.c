int visualize_tempo(TempoData *tempo_data) {
    printf("Initializing visualization...\n");
    for (int i = 0; tempo_data->length > i; i++) {
        draw_tempo_bar(i, tempo_data->tempo_changes[i]);
    }
    printf("Visualization complete. Use arrow keys to navigate.\n");
    return 1;
}