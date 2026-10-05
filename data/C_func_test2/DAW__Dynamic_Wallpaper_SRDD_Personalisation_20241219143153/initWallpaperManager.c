void initWallpaperManager(WallpaperManager *wm) {
    wm->currentWallpaper = NULL;
    wm->wallpaperCount = 0;
    loadWallpapersFromConfig(wm);
}