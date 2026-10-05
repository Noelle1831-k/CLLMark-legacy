void processFile() {
        string filePath;
        cout << "Enter the path of the music file to upload: ";
        cin >> filePath;
        if (isSupportedFormat(filePath) && fileHandler.uploadFile(filePath)) {
            cout << "File uploaded successfully!" << endl;
            melodyAnalyzer.analyzeMelody(filePath);
            string style;
            int level;
            cout << "Enter harmonization style (e.g., classical, jazz): ";
            cin >> style;
            cout << "Enter harmony level (1-10): ";
            cin >> level;
            harmonyGenerator.generateHarmony(style, level);
        } else {
            cout << "Failed to upload file. Please check the path and format, then try again." << endl;
        }
    }