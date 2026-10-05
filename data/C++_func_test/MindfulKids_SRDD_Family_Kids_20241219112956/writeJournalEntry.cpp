void writeJournalEntry() {
        string entry;
        cout << "Please write your journal entry: ";
        cin.ignore();  
        getline(cin, entry);
        journalEntries.push_back(entry);
        cout << "Your entry has been saved!" << endl;
    }