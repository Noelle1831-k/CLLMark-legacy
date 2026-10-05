void MainApplication::handleInput() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            createUserProfile();
            break;
        case 2:
            joinBookClub();
            break;
        case 3:
            createBookClub();
            break;
        case 4:
            participateInDiscussions();
            break;
        case 5:
            shareBookRecommendations();
            break;
        case 6:
            for (auto &pair : users) {
                pair.second.viewProfile();
            }
            break;
        case 7:
            for (auto &pair : bookClubs) {
                pair.second.viewClubDetails();
            }
            break;
        case 8:
            cout << "Exiting the application...\n";
            exit(0);
        default:
            cout << "Invalid choice. Try again.\n";
    }
}