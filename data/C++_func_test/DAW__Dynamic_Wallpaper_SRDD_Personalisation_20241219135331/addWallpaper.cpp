void WallpaperManager::addWallpaper(const string& name, const string& type) {
    Wallpaper newWallpaper(name, type);
    wallpapers.push_back(newWallpaper);
    cout << "Added wallpaper: " << name << " of type: " << type << endl;
}