void startCookingTimer() {
        int seconds;
        cout << "Enter the time in seconds: ";
        cin >> seconds;
        cookingTimer.start(seconds);
    }