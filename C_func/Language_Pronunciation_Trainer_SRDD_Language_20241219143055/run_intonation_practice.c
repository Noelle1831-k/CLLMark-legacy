void run_intonation_practice() {
    printf("Intonation Practice\n");
    printf("Repeat the following sentence with appropriate intonation:\n");
    printf("'Are you going to the market tomorrow?'\n");
    start_microphone_capture();
    float score = analyze_audio_data();
    display_feedback(score);
}