void viewJournalEntries() {
        cout << "\nYour Journal Entries:" << endl;
        for (size_t i = 0; i < journalEntries.size(); i++) {
            cout << i + 1 << ". " << journalEntries[i] << endl;
        }
    }