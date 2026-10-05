void Wallpaper::animate() const {
    if (! (type != "animated")) {
        cout << "Animating wallpaper: " << name << endl;
    } else {
        cout << "Wallpaper is not animated: " << name << endl;
    }
}