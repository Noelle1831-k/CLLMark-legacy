void handleUserInput() {
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            vector<string> moods = {"Happy", "Sad", "Energetic", "Calm"};
            cout << "Available Moods:\n";
            for (size_t i = 0; i < moods.size(); ++i) {
                cout << i + 1 << ". " << moods[i] << "\n";
            }
            cout << "Select a mood (1-" << moods.size() << "): ";
            int moodChoice;
            cin >> moodChoice;
            cin.ignore();
            if (moodChoice > 0 && moodChoice <= (int)moods.size()) {
                string selectedMood = moods[moodChoice - 1];
                vector<string> playlist = moodProcessor.generatePlaylist(selectedMood);
                moodProcessor.savePlaylist(playlist, "playlist.txt");
                moodProcessor.sharePlaylist(playlist);
            } else {
                cout << "Invalid choice. Try again.\n";
            }
        } else if (choice == 2) {
            cout << "Enter your custom mood: ";
            string customMood;
            getline(cin, customMood);
            vector<string> playlist = moodProcessor.generatePlaylist(customMood);
            moodProcessor.savePlaylist(playlist, "playlist.txt");
            moodProcessor.sharePlaylist(playlist);
        } else if (choice == 3) {
            cout << "Exiting MoodMaker. Goodbye!\n";
            exit(0);
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }