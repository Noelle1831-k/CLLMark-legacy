void Dashboard::navigateOptions() {
    FeedbackForm form;
    FeedbackManager manager;
    DataAnalyzer analyzer;
    int choice;
    do {
        cout << "\n1. Create Feedback Form\n2. Distribute Form\n3. Collect Responses\n4. Analyze Data\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                form.createForm();
                break;
            case 2:
                manager.distributeForm();
                break;
            case 3:
                manager.collectResponses();
                break;
            case 4:
                analyzer.analyzeData();
                analyzer.generateInsights();
                analyzer.visualizeData();
                break;
            case 5:
                cout << "Exiting the application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}