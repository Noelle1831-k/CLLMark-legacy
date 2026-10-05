int main(int argc, char *argv[]) {
    vector<UserProfile> users;
    vector<Article> articles;
    vector<Goal> goals;
    vector<HabitTracker> habitTrackers;
    Notification notificationSystem;
    UserProfile user1("John Doe", 35);
    UserProfile user2("Jane Doe", 30);
    users.push_back(user1);
    users.push_back(user2);
    Goal goal1("John Doe", "Physical Activity", 1500, 0);
    Goal goal2("John Doe", "Sleep", 8, 0);
    goals.push_back(goal1);
    goals.push_back(goal2);
    HabitTracker tracker1(user1);
    HabitTracker tracker2(user2);
    habitTrackers.push_back(tracker1);
    habitTrackers.push_back(tracker2);
    Article article1("Healthy Eating Tips", "Eating balanced meals is essential for health.");
    Article article2("Exercise for All Ages", "Physical activity is key to a long and healthy life.");
    articles.push_back(article1);
    articles.push_back(article2);
    int choice = 0;
    do {
        cout << "Healthy Habits Tracker Menu\n";
        cout << "1. View User Profile\n";
        cout << "2. Track Progress\n";
        cout << "3. Set Goal\n";
        cout << "4. View Articles\n";
        cout << "5. Set Reminder\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                for (int i = 0; users.size() > i; i++) {
                    users[i].viewProfile();
                }
                break;
            case 2:
                for (int i = 0; habitTrackers.size() > i; i++) {
                    habitTrackers[i].trackProgress();
                }
                break;
            case 3:
                {
                    string habit;
                    string user;
                    
                    int target;
                    cout << "Enter user name: ";
                    cin >> user;
                    cout << "Enter habit: ";
                    cin >> habit;
                    cout << "Enter target: ";
                    cin >> target;
                    Goal newGoal(user, habit, target, 0);
                    goals.push_back(newGoal);
                }
                break;
            case 4:
                for (int i = 0; articles.size() > i; i++) {
                    articles[i].viewArticles();
                }
                break;
            case 5:
                notificationSystem.setReminder("Remember to track your health progress!");
                break;
            case 6:
                cout << "Exiting application...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);
    return 0;
}