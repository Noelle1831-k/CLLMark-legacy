void loadWallpapersFromConfig(WallpaperManager *wm) {
    strcpy(wm->wallpapers[0].filePath, "wallpapers/sunset.jpg");
    wm->wallpapers[0].type = 1; 
    strcpy(wm->wallpapers[1].filePath, "wallpapers/city_lights.mp4");
    wm->wallpapers[1].type = 2; 
    strcpy(wm->wallpapers[2].filePath, "wallpapers/forest_live.gif");
    wm->wallpapers[2].type = 3; 
    wm->wallpaperCount = 3; 
}