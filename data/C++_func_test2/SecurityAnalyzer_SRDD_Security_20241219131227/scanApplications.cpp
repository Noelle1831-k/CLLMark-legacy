void ApplicationScanner::scanApplications() {
    const char* applications[] = {"App1", "App2", "App3"};
    int i;
    for (i = 0; i < 3; i++) {
        cout << "Scanning application: " << applications[i] << endl;
        cout << "No vulnerabilities found in " << applications[i] << endl;
    }
}