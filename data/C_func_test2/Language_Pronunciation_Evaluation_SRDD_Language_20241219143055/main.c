int main() {
    char target_phrase[256];
    char recording_file[] = "user_recording.wav";
    float pronunciation_score;
    printf("Enter the target phrase for pronunciation practice: ");
    fgets(target_phrase, sizeof(target_phrase), stdin);
    target_phrase[strcspn(target_phrase, "\n")] = '\0'; 
    printf("Please record your pronunciation of the following phrase: \"%s\"\n", target_phrase);
    if (start_recording(recording_file) != 0) {
        fprintf(stderr, "Error: Unable to start recording. Exiting application.\n");
        return EXIT_FAILURE;
    }
    printf("Recording in progress... Please speak clearly.\n");
    sleep(5); 
    if (stop_recording() != 0) {
        fprintf(stderr, "Error: Unable to stop recording. Exiting application.\n");
        return EXIT_FAILURE;
    }
    printf("Recording completed. Analyzing pronunciation...\n");
    pronunciation_score = analyze_audio(recording_file);
    generate_feedback(pronunciation_score);
    return 0;
}