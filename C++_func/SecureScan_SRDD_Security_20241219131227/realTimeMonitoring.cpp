void Scanner::realTimeMonitoring() {
    cout << "Real-time monitoring activated. Press 'q' to stop." << endl;
    while (true) {
        this_thread::sleep_for(chrono::seconds(5));
        if (rand() % 5 == 0) {
            cout << "Real-time alert: Threat detected!" << endl;
        }
        if (cin.peek() == 'q') {
            cin.ignore();
            cout << "Real-time monitoring stopped." << endl;
            break;
        }
    }
}