void SecureBrowser::protect() {
    cout << "Activating secure browsing mode...\n";
    for (int i = 0; i < blockedWebsites.size(); i++) {
        cout << "Blocked website: " << blockedWebsites[i] << "\n";
    }
}