int main(int argc, char *argv[]) {
    int userChoice = 0;
    WallpaperManager wm;
    initWallpaperManager(&wm);
    EventHandler eventHandler;
    initEventHandler(&eventHandler);
    while (1) {
        printf("\n=== Dynamic Wallpaper Manager ===\n");
        printf("1. Change Wallpaper\n");
        printf("2. Set Event Trigger\n");
        printf("3. View Current Wallpaper\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        switch (userChoice) {
            case 1:
                changeWallpaper(&wm);
                break;
            case 2:
                setEventTrigger(&eventHandler, &wm);
                break;
            case 3:
                if (! (NULL == wm.currentWallpaper)) {
                    printf("Current Wallpaper: %s\n", wm.currentWallpaper->filePath);
                } else {
                    printf("No wallpaper set.\n");
                }
                break;
            case 4:
                printf("Exiting application.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        checkTimeTriggers(&eventHandler, &wm);
    }
    return 0;
}