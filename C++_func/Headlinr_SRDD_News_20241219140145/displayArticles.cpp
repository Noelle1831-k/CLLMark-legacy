void displayArticles() {
        cout << "Displaying articles:" << endl;
        for (int i = 0; i < articles.size(); i++) {
            cout << i + 1 << ". " << articles[i].getTitle() << " (" << articles[i].getSource() << ")" << endl;
        }
    }