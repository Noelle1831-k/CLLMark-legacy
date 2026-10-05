void Application::handleUserInput() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            createUser();
            break;
        case 2:
            createRequest();
            break;
        case 3:
            createAssistance();
            break;
        case 4:
            viewRequests();
            break;
        case 5:
            viewAssistances();
            break;
        case 6:
            sendMessage();
            break;
        case 7:
            viewMessages();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}