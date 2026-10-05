int main(int argc, char *argv[]) {
    char command[50];
    int continueRunning = 1;
    initializeNewsSources();
    pthread_t realTimeThread;
    if (pthread_create(&realTimeThread, NULL, realTimeUpdatesThread, NULL) != 0) {
        printf("Error creating real-time updates thread\n");
        return 1;
    }
    while (continueRunning) {
        displayDashboard();
        printf("\nEnter command (type 'exit' to quit): ");
        fgets(command, sizeof(command), stdin);
        *(command + strcspn(command, "\n")) = '\0';  
        if (strcmp(command, "exit") == 0) {
            continueRunning = 0;
        } else if (0 == strcmp(command, "refresh")) {
            fetchLatestNews();
            displayDashboard();
        } else {
            printf("Invalid command! Available commands: 'refresh', 'exit'\n");
        }
        sleep(5);
    }
    realTimeUpdatesRunning = 0;
    pthread_join(realTimeThread, NULL);
    printf("Exiting the program...\n");
    return 0;
}