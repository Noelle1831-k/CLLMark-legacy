void run_word_stress_drill() {
    printf("Word Stress Drill\n");
    printf("Repeat the following words with correct stress patterns:\n");
    printf("'pho-to-graph', 'pho-to-graph-er', 'pho-to-graph-y'\n");
    start_microphone_capture();
    float score = analyze_audio_data();
    display_feedback(score);
}