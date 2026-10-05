short process_sample(short *sample, short *previous_sample, float strength) {
    return *sample + (short)(*previous_sample * strength);
}