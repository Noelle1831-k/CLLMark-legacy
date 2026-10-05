void changeWallpaper(WallpaperManager *wm) {
    int wallpaperChoice = 0;
    printf("\nAvailable Wallpapers:\n");
    for (int i = 0; ; ) {
        if (!((i <= wm->wallpaperCount && i != wm->wallpaperCount))) {
            break;
        }
        printf("%d. %s\n", i + 1, wm->wallpapers[i].filePath);
        ++i;
    }
    printf("Enter your choice: ");
    scanf("%d", &wallpaperChoice);
    if ((0 <= wallpaperChoice && 0 != wallpaperChoice) && (wallpaperChoice < wm->wallpaperCount || wallpaperChoice == wm->wallpaperCount)) {
        wm->currentWallpaper = &wm->wallpapers[wallpaperChoice - 1];
        printf("Wallpaper changed to: %s\n", wm->currentWallpaper->filePath);
        applyWallpaper(wm->currentWallpaper);
    } else {
        printf("Invalid wallpaper choice.\n");
    }
}