void free_tempo_data(TempoData *tempo_data) {
    if (tempo_data) {
        free(tempo_data->tempo_changes);
        free(tempo_data);
    }
}