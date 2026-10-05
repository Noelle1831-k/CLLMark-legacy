int main() {
    vector<User> users;
    vector<Book> books;
    RecommendationSystem recommendationSystem;
    books.push_back(Book("To Kill a Mockingbird", "Harper Lee", "Fiction", "A novel about racism and justice in the South.", 4.5));
    books.push_back(Book("1984", "George Orwell", "Dystopian", "A story of a totalitarian regime.", 4.8));
    books.push_back(Book("Moby Dick", "Herman Melville", "Adventure", "The tale of a sea captain's obsession.", 4.2));
    while (true) {
        cout << "\nWelcome to BookLift! Choose an option:\n";
        cout << "1. Create User Profile\n";
        cout << "2. Rate a Book\n";
        cout << "3. Get Recommendations\n";
        cout << "4. Exit\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            string name;
            cout << "Enter your name: ";
            cin >> name;
            users.push_back(User(name));
            cout << "Profile created successfully!\n";
        } else if (choice == 2) {
            string name;
            cout << "Enter your name: ";
            cin >> name;
            bool userFound = false;
            for (int i = 0; i < users.size(); i++) {
                if (users[i].getName() == name) {
                    userFound = true;
                    string bookTitle;
                    int rating;
                    cout << "Enter book title: ";
                    cin.ignore();
                    getline(cin, bookTitle);
                    cout << "Enter rating (1-5): ";
                    cin >> rating;
                    users[i].addRating(bookTitle, rating);
                    cout << "Rating added!\n";
                    break;
                }
            }
            if (!userFound) {
                cout << "User not found.\n";
            }
        } else if (choice == 3) {
            string name;
            cout << "Enter your name: ";
            cin >> name;
            bool userFound = false;
            for (int i = 0; i < users.size(); i++) {
                if (users[i].getName() == name) {
                    userFound = true;
                    vector<Book> recommendations = recommendationSystem.generateRecommendations(users[i], books);
                    cout << "Recommendations for " << name << ":\n";
                    for (int j = 0; j < recommendations.size(); j++) {
                        cout << recommendations[j].getTitle() << " - " << recommendations[j].getAuthor() << "\n";
                    }
                    break;
                }
            }
            if (!userFound) {
                cout << "User not found.\n";
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}