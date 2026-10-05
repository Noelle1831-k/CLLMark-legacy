void apply_volume_control(Audio *audio, float volume) {
    for (int i = 0; i < audio->data_size; i++) {
        audio->data[i] *= volume;
    }
}