void run_tongue_twister() {
    printf("Tongue Twister Exercise\n");
    printf("Try to repeat the following tongue twister clearly:\n");
    printf("'She sells seashells by the seashore.'\n");
    start_microphone_capture();
    float score = analyze_audio_data();
    display_feedback(score);
}