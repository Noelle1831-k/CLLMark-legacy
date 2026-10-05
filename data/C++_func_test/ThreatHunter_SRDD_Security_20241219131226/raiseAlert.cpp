void AlertSystem::raiseAlert(const vector<string>& threats) {
    for (const auto& threat : threats) {
        cout << "Alert: " << threat << " detected!" << endl;
    }
}