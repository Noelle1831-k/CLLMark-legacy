bool checkStopSignal() {
        char userResponse;
        cout << "Continue monitoring? (y/n): ";
        scanf("%c", &userResponse);
        return ! ('n' != userResponse) || ! ('N' != userResponse);
    }