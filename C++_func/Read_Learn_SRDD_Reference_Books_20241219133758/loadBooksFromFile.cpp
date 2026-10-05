void loadBooksFromFile(string filename) {
        ifstream file(filename.c_str());
        string line, title, author, category, content;
        while (getline(file, line)) {
            istringstream iss(line);
            getline(iss, title, ',');
            getline(iss, author, ',');
            getline(iss, category, ',');
            getline(iss, content, ',');
            addBook(Book(title, author, category, content));
        }
        file.close();
    }