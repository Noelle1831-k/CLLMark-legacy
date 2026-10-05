void startSession(const string& sessionType) {
        cout << "\nStarting " << sessionType << " session." << endl;
        this_thread::sleep_for(chrono::seconds(2));  
        cout << "Session started. Focus on your breath!" << endl;
        this_thread::sleep_for(chrono::seconds(5));  
        endSession();
    }