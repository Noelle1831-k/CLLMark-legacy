void setEventTrigger(EventHandler *eventHandler, WallpaperManager *wm) {
    int eventChoice = 0;
    printf("\nSet an event trigger:\n");
    printf("1. Time-based trigger (Change wallpaper at specific time)\n");
    printf("2. Custom event trigger\n");
    printf("Enter your choice: ");
    scanf("%d", &eventChoice);
    switch (eventChoice) {
        case 1:
            printf("Enter hour (0-23): ");
            scanf("%d", &eventHandler->timeTrigger.hour);
            printf("Enter minute (0-59): ");
            scanf("%d", &eventHandler->timeTrigger.minute);
            printf("Time trigger set for %02d:%02d.\n", eventHandler->timeTrigger.hour, eventHandler->timeTrigger.minute);
            break;
        case 2:
            eventHandler->userEventTriggered = 1;
            printf("Custom event trigger enabled.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}