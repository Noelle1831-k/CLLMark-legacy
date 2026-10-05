bool checkStopSignal() {
        char userResponse;
        cout << "Continue monitoring? (y/n): ";
        cin >> userResponse;
        return userResponse == 'n' || userResponse == 'N';
    }