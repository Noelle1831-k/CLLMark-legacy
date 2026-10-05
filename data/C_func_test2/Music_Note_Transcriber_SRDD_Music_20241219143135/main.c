int main() {
    int choice;
    char fileName[100];
    char *transcription = NULL;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Recording audio...\n");
                double *audioData = recordAudio();
                printf("Processing audio...\n");
                double *features = extractFeatures(audioData);
                printf("Recognizing notes...\n");
                transcription = recognizeNotes(features);
                printf("Transcription: %s\n", transcription);
                free(audioData);
                free(features);
                break;
            case 2:
                printf("Enter file name to load transcription: ");
                scanf("%s", fileName);
                transcription = loadTranscription(fileName);
                if (transcription != NULL) {
                    printf("Loaded Transcription: %s\n", transcription);
                } else {
                    printf("Error loading transcription.\n");
                }
                break;
            case 3:
                if (transcription != NULL) {
                    printf("Enter file name to save transcription: ");
                    scanf("%s", fileName);
                    saveTranscription(fileName, transcription);
                    printf("Transcription saved successfully.\n");
                } else {
                    printf("No transcription available to save.\n");
                }
                break;
            case 4:
                printf("Exiting application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        if (transcription) {
            free(transcription);
            transcription = NULL;
        }
    }
    return 0;
}