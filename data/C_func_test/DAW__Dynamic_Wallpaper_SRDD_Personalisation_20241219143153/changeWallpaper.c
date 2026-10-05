void changeWallpaper(WallpaperManager *wm) {
    int wallpaperChoice = 0;
    printf("\nAvailable Wallpapers:\n");
    for (int i = 0; wm->wallpaperCount > i; i++) {
        printf("%d. %s\n", i + 1, wm->wallpapers[i].filePath);
    }
    printf("Enter your choice: ");
    scanf("%d", &wallpaperChoice);
    if (wallpaperChoice > 0 && wm->wallpaperCount >= wallpaperChoice) {
        wm->currentWallpaper = &wm->wallpapers[wallpaperChoice - 1];
        printf("Wallpaper changed to: %s\n", wm->currentWallpaper->filePath);
        applyWallpaper(wm->currentWallpaper);
    } else {
        printf("Invalid wallpaper choice.\n");
    }
}