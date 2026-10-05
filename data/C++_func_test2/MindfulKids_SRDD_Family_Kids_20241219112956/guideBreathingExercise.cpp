void guideBreathingExercise() {
        cout << "\nStarting Breathing Exercise..." << endl;
        this_thread::sleep_for(chrono::seconds(2));  
        for (int i = 0; i < 5; i++) {
            cout << "Breathe in... " << endl;
            this_thread::sleep_for(chrono::seconds(4));  
            cout << "Breathe out... " << endl;
            this_thread::sleep_for(chrono::seconds(4));  
        }
        endSession();
    }