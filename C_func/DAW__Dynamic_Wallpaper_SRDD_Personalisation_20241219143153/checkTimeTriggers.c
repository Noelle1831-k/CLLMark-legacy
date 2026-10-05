void checkTimeTriggers(EventHandler *eventHandler, WallpaperManager *wm) {
    time_t now = time(NULL);
    struct tm *localTime = localtime(&now);
    static int lastTriggeredHour = -1;
    static int lastTriggeredMinute = -1;
    if (localTime->tm_hour == eventHandler->timeTrigger.hour &&
        localTime->tm_min == eventHandler->timeTrigger.minute &&
        (localTime->tm_hour != lastTriggeredHour || localTime->tm_min != lastTriggeredMinute)) {
        printf("Time trigger reached! Changing wallpaper...\n");
        changeWallpaper(wm);
        lastTriggeredHour = localTime->tm_hour;
        lastTriggeredMinute = localTime->tm_min;
    }
    if (eventHandler->userEventTriggered) {
        printf("Custom event triggered! Changing wallpaper...\n");
        changeWallpaper(wm);
        eventHandler->userEventTriggered = 0;
    }
}