void saveHarmonizedFile() {
        string savePath;
        cout << "Enter the path to save the harmonized file: ";
        cin >> savePath;
        if (fileHandler.saveFile(savePath)) {
            cout << "File saved successfully!" << endl;
        } else {
            cout << "Failed to save file. Please try again." << endl;
        }
    }