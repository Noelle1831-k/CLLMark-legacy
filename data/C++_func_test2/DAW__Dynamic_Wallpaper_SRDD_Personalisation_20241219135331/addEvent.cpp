void EventScheduler::addEvent(const string& eventName, const string& time, const string& wallpaperName) {
    events[eventName] = wallpaperName;
    cout << "Added event: " << eventName << " at: " << time << " for wallpaper: " << wallpaperName << endl;
}