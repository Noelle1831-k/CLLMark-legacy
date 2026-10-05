void AppInterface::handleUserInput(string input) {
    if (input == "track") {
        int hours = -1, minutes = -1;
        while (hours < 0 || minutes < 0) {
            cout << "Enter hours and minutes worked (e.g., 2 30): ";
            string line;
            getline(cin, line);
            stringstream ss(line);
            if (!(ss >> hours >> minutes) || hours < 0 || minutes < 0) {
                cout << "Invalid input. Please enter non-negative integers for hours and minutes.\n";
                hours = -1;
                minutes = -1;
            }
        }
        manager.trackTime(hours, minutes);
    } else if (input == "schedule") {
        string taskName;
        int duration = -1;
        cout << "Enter task name: ";
        getline(cin, taskName);
        while (duration < 0) {
            cout << "Enter task duration (in minutes): ";
            string line;
            getline(cin, line);
            stringstream ss(line);
            if (!(ss >> duration) || duration < 0) {
                cout << "Invalid input. Please enter a non-negative integer for duration.\n";
                duration = -1;
            }
        }
        manager.scheduleTask(taskName, duration);
    } else if (input == "analyze") {
        vector<int> sampleData = {5, 7, 8, 6, 5, 9, 7}; 
        analyzer.analyzeTimeData(sampleData);
        analyzer.displayAnalysisSummary();
    } else if (input == "summary") {
        manager.displayTotalTime();
        manager.calculateProductivity();
        manager.displaySchedule();
    } else if (input == "help") {
        displayHelp();
    } else {
        cout << "Invalid command. Type 'help' for a list of commands.\n";
    }
}