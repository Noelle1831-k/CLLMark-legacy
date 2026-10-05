void Scanner::scanApplications() {
    cout << "Scanning applications for threats..." << endl;
    vector<string> applications = {"app1", "app2", "app3"};
    for (size_t i = 0; i < applications.size(); i++) {
        cout << "Scanning " << applications[i] << "... ";
        if (rand() % 2 == 0) {
            cout << "Threat detected!" << endl;
        } else {
            cout << "No threats found." << endl;
        }
    }
}