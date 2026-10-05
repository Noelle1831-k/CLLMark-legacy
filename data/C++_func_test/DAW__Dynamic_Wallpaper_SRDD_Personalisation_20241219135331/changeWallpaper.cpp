void WallpaperManager::changeWallpaper(const string& name) {
    for (const auto& wallpaper : wallpapers) {
        if (wallpaper.getName() == name) {
            currentWallpaper = name;
            wallpaper.display();
            cout << "Changed to wallpaper: " << name << endl;
            return;
        }
    }
    cout << "Wallpaper not found: " << name << endl;
}