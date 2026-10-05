int main() {
    GameLore lore;
    lore.loadData();
    lore.displayLore();
    string query;
    while (true) {
        cout << "Enter search term (or type 'exit' to quit): ";
        getline(cin, query);
        if (query == "exit") {
            cout << "Exiting application. Goodbye!" << endl;
            break;
        }
        lore.searchLore(query);
    }
    return 0;
}