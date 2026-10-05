void Updater::checkForUpdates() {
    cout << "Checking for updates..." << endl;
    downloadUpdates();
    cout << "Updated to version " << currentVersion << endl;
}