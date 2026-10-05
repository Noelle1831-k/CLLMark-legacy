void changeWallpaper(WallpaperManager *wm) {
    int wallpaperChoice = 0;
    printf("\nAvailable Wallpapers:\n");
    for (int i = 0; i < wm->wallpaperCount; i++) {
        printf("%d. %s\n", i + 1, wm->wallpapers[i].filePath);
    }
    printf("Enter your choice: ");
    scanf("%d", &wallpaperChoice);
    if (wallpaperChoice > 0 && wallpaperChoice <= wm->wallpaperCount) {
        wm->currentWallpaper = &wm->wallpapers[wallpaperChoice - 1];
        printf("Wallpaper changed to: %s\n", wm->currentWallpaper->filePath);
        applyWallpaper(wm->currentWallpaper);
    } else {
        printf("Invalid wallpaper choice.\n");
    }
}