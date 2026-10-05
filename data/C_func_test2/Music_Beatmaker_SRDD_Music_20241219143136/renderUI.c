void renderUI(UIManager* manager) {
    printf("Rendering UI...\n");
    for (int i = 0; i < BEAT_SEQUENCE_LENGTH; i++) {
        if (manager->selectedPosition == i) {
            printf("[X] ");
        } else {
            printf("[ ] ");
        }
    }
    printf("\n");
}