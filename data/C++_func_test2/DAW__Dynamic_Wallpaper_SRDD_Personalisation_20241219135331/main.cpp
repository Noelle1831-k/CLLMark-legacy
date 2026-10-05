int main() {
    WallpaperManager manager;
    EventScheduler scheduler;
    TimeManager timeManager;
    cout << "Welcome to the Dynamic Wallpaper Application!" << endl;
    manager.addWallpaper("Sunset", "animated");
    manager.addWallpaper("Rain", "live");
    manager.scheduleWallpaperChange("Sunset", "18:00");
    scheduler.addEvent("Party Mode", "20:00", "Rain");
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                string name, type;
                cout << "Enter wallpaper name: ";
                cin >> name;
                cout << "Enter wallpaper type (animated/live/custom): ";
                cin >> type;
                manager.addWallpaper(name, type);
                break;
            }
            case 2: {
                string name;
                cout << "Enter wallpaper name to remove: ";
                cin >> name;
                manager.removeWallpaper(name);
                break;
            }
            case 3: {
                string name;
                cout << "Enter wallpaper name to change to: ";
                cin >> name;
                manager.changeWallpaper(name);
                break;
            }
            case 4: {
                string name, time;
                cout << "Enter wallpaper name: ";
                cin >> name;
                cout << "Enter time (HH:MM): ";
                cin >> time;
                manager.scheduleWallpaperChange(name, time);
                break;
            }
            case 5: {
                string eventName, time, wallpaperName;
                cout << "Enter event name: ";
                cin >> eventName;
                cout << "Enter time (HH:MM): ";
                cin >> time;
                cout << "Enter wallpaper name: ";
                cin >> wallpaperName;
                scheduler.addEvent(eventName, time, wallpaperName);
                break;
            }
            case 6: {
                string eventName;
                cout << "Enter event name to remove: ";
                cin >> eventName;
                scheduler.removeEvent(eventName);
                break;
            }
            case 7: {
                string eventName;
                cout << "Enter event name to trigger: ";
                cin >> eventName;
                scheduler.triggerEvent(eventName);
                break;
            }
            case 8: {
                manager.displayCurrentWallpaper();
                break;
            }
            case 9: {
                cout << "Exiting application. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}