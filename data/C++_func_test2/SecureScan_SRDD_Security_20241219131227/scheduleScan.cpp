void Scheduler::scheduleScan() {
    cout << "Scheduling a scan every 10 seconds..." << endl;
    for (int i = 0; i < 3; i++) {
        this_thread::sleep_for(chrono::seconds(10));
        cout << "Scheduled scan in progress..." << endl;
    }
    cout << "Scheduled scans completed." << endl;
}