void SecureBrowser::blockWebsite(const string &url) {
    cout << "Blocking website: " << url << "\n";
    blockedWebsites.push_back(url);
}