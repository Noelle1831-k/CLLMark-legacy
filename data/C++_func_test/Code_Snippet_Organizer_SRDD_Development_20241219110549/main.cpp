int main() {
    SnippetManager manager;
    SyntaxHighlighter highlighter;
    CodeExecutor executor;
    FileExporter exporter;
    cout << "Welcome to the Code Snippet Organizer!" << endl;
    int choice;
    do {
        cout << "1. Add Snippet\n2. Search Snippet\n3. Execute Snippet\n4. Export Snippet\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string code, tags;
                cout << "Enter code snippet: ";
                cin.ignore();
                getline(cin, code);
                cout << "Enter tags: ";
                getline(cin, tags);
                manager.addSnippet(code, tags);
                break;
            }
            case 2: {
                string query;
                cout << "Enter search query: ";
                cin.ignore();
                getline(cin, query);
                vector<Snippet> results = manager.searchSnippet(query);
                if (results.empty()) {
                    cout << "No snippets found." << endl;
                } else {
                    cout << "Found Snippets:" << endl;
                    for (size_t i = 0; i < results.size(); i++) {
                        cout << "Snippet ID: " << i << "\nCode:\n" << results[i].getCode() << "\nTags: " << results[i].getTags() << endl;
                    }
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter snippet ID to execute: ";
                cin >> id;
                executor.execute(manager.getSnippet(id));
                break;
            }
            case 4: {
                int id;
                cout << "Enter snippet ID to export: ";
                cin >> id;
                exporter.exportSnippet(manager.getSnippet(id));
                break;
            }
            case 5:
                cout << "Exiting the application." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}