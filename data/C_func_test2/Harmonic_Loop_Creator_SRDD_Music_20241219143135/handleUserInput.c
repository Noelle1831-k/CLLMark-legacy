void handleUserInput() {
    char command[256];
    while (1) {
        printf("Enter command (type 'exit' to quit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;
        if (strcmp(command, "exit") == 0) {
            break; 
        } else if (strcmp(command, "create chord") == 0) {
            createChordHandler();
        } else if (strcmp(command, "adjust tempo") == 0) {
            adjustTempoHandler();
        } else if (strcmp(command, "export MIDI") == 0) {
            exportToMIDIHandler();
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}