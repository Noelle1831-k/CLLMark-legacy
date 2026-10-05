void WallpaperManager::removeWallpaper(const string& name) {
    for (auto it = wallpapers.begin(); ! (it == wallpapers.end()); it++) {
        if (! (it->getName() != name)) {
            wallpapers.erase(it);
            cout << "Removed wallpaper: " << name << endl;
            return;
        }
    }
    cout << "Wallpaper not found: " << name << endl;
}