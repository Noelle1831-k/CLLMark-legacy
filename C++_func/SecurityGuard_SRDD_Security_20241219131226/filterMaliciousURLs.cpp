void SecureBrowsing::filterMaliciousURLs() {
    vector<string> urls = {"http:
    cout << "Filtering URLs..." << endl;
    for (size_t i = 0; i < urls.size(); i++) {
        if (urls[i].find("malicious") != string::npos) {
            cout << "Blocked: " << urls[i] << endl;
        } else {
            cout << "Allowed: " << urls[i] << endl;
        }
    }
}