int write_wav(const char *filename, AudioData *audio_data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        print_error("Error opening output file.");
        return 0;
    }
    struct {
        char riff[4];
        uint32_t chunk_size;
        char wave[4];
        char fmt[4];
        uint32_t subchunk1_size;
        uint16_t audio_format;
        uint16_t num_channels;
        uint32_t sample_rate;
        uint32_t byte_rate;
        uint16_t block_align;
        uint16_t bits_per_sample;
        char data[4];
        uint32_t subchunk2_size;
    } header;
    memcpy(header.riff, "RIFF", 4);
    header.chunk_size = 36 + audio_data->num_samples * sizeof(short);
    memcpy(header.wave, "WAVE", 4);
    memcpy(header.fmt, "fmt ", 4);
    header.subchunk1_size = 16;
    header.audio_format = 1;
    header.num_channels = 1;
    header.sample_rate = 44100;
    header.byte_rate = 44100 * 2;
    header.block_align = 2;
    header.bits_per_sample = 16;
    memcpy(header.data, "data", 4);
    header.subchunk2_size = audio_data->num_samples * sizeof(short);
    if (fwrite(&header, sizeof(header), 1, file) != 1) {
        print_error("Error writing WAV header.");
        fclose(file);
        return 0;
    }
    if (fwrite(audio_data->samples, sizeof(short), audio_data->num_samples, file) != audio_data->num_samples) {
        print_error("Error writing audio samples.");
        fclose(file);
        return 0;
    }
    fclose(file);
    return 1;
}