void WallpaperManager::browseWallpapers() {
    cout << "Available Wallpapers:" << endl;
    for (const auto &wallpaper : wallpapers) {
        cout << wallpaper << endl;
    }
}