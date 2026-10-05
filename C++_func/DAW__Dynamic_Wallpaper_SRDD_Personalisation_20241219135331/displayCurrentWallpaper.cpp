void WallpaperManager::displayCurrentWallpaper() const {
    if (currentWallpaper.empty()) {
        cout << "No wallpaper is currently set." << endl;
    } else {
        cout << "Current wallpaper: " << currentWallpaper << endl;
    }
}