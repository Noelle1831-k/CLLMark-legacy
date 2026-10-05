bool checkStopSignal() {
        char userResponse;
        printf("Continue monitoring? (y/n): ");
        cin >> userResponse;
        return userResponse == 'n' || userResponse == 'N';
    }