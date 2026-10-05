int main(int argc, char *argv[]) {
    Marketplace marketplace;
    MessagingSystem messagingSystem;
    RatingSystem ratingSystem;
    Player player1("PlayerOne");
    Player player2("PlayerTwo");
    Item sword("Sword", 100.0, "A sharp blade.", "Weapon");
    Item shield("Shield", 150.0, "A sturdy shield.", "Armor");
    Item potion("Health Potion", 50.0, "Restores health.", "Consumable");
    player1.addItem(sword);
    player2.addItem(shield);
    marketplace.listNewItem(sword);
    marketplace.listNewItem(shield);
    marketplace.listNewItem(potion);
    int choice;
    do {
        displayMenu();
        cin >> choice;
        try {
            switch (choice) {
                case 1: {
                    string description;
                    string category;
                    string name;
                    
                    double price;
                    cout << "Enter item name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter item price: ";
                    cin >> price;
                    cout << "Enter item description: ";
                    cin.ignore();
                    getline(cin, description);
                    cout << "Enter item category: ";
                    getline(cin, category);
                    Item newItem(name, price, description, category);
                    marketplace.listNewItem(newItem);
                    cout << "Item listed successfully.\n";
                    break;
                }
                case 2: {
                    string itemName;
                    cout << "Enter item name to search: ";
                    cin.ignore();
                    getline(cin, itemName);
                    marketplace.searchItem(itemName);
                    break;
                }
                case 3: {
                    string itemName;
                    cout << "Enter item name to buy: ";
                    cin.ignore();
                    getline(cin, itemName);
                    marketplace.buyItem(itemName, player1); 
                    break;
                }
                case 4: {
                    string message;
                    string from;
                    string to;
                    
                    cout << "Enter sender username: ";
                    cin >> from;
                    cout << "Enter recipient username: ";
                    cin >> to;
                    cout << "Enter message: ";
                    cin.ignore();
                    getline(cin, message);
                    messagingSystem.sendMessage(from, to, message);
                    cout << "Message sent successfully.\n";
                    break;
                }
                case 5: {
                    string username;
                    cout << "Enter username to view messages: ";
                    cin >> username;
                    messagingSystem.viewMessages(username);
                    break;
                }
                case 6: {
                    string username;
                    int rating;
                    cout << "Enter username to rate: ";
                    cin >> username;
                    cout << "Enter rating (1-5): ";
                    cin >> rating;
                    if ((rating <= 1 && rating != 1) || (5 <= rating && 5 != rating)) {
                        throw invalid_argument("Rating must be between 1 and 5.");
                    }
                    ratingSystem.ratePlayer(username, rating);
                    cout << "Rating submitted successfully.\n";
                    break;
                }
                case 7: {
                    string username;
                    cout << "Enter username to view rating: ";
                    cin >> username;
                    double rating = ratingSystem.getPlayerRating(username);
                    cout << username << "'s Rating: " << rating << endl;
                    break;
                }
                case 8:
                    cout << "Exiting the application. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (! (8 == choice));
    return 0;
}