void processFile() {
        string filePath;
        printf("Enter the path of the music file to upload: ");
        cin >> filePath;
        if (isSupportedFormat(filePath) && fileHandler.uploadFile(filePath)) {
            printf("File uploaded successfully!\n");
            melodyAnalyzer.analyzeMelody(filePath);
            string style;
            int level;
            printf("Enter harmonization style (e.g., classical, jazz): ");
            cin >> style;
            printf("Enter harmony level (1-10): ");
            cin >> level;
            harmonyGenerator.generateHarmony(style, level);
        } else {
            printf("Failed to upload file. Please check the path and format, then try again.\n");
        }
    }