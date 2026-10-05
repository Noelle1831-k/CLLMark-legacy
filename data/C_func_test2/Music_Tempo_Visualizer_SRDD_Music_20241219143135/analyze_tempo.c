TempoData* analyze_tempo(AudioData *audio_data) {
    TempoData *tempo_data = (TempoData *)malloc(sizeof(TempoData));
    if (!tempo_data) {
        return NULL;
    }
    tempo_data->length = audio_data->length / 10;
    tempo_data->tempo_changes = (int *)malloc(tempo_data->length * sizeof(int));
    if (!tempo_data->tempo_changes) {
        free(tempo_data);
        return NULL;
    }
    for (int i = 0; i < tempo_data->length; i++) {
        tempo_data->tempo_changes[i] = (int)(100 + 100 * sin(i * 0.1));
    }
    return tempo_data;
}