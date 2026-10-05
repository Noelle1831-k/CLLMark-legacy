void run() {
        cout << "Welcome to Music Tempo Visualizer!" << endl;
        string filePath = ui.getFilePath();
        if (fileHandler.loadFile(filePath)) {
            auto tempoData = tempoAnalyzer.analyze(fileHandler.getAudioData());
            if (tempoData.empty()) {
                cout << "No tempo data extracted. Please check the file format." << endl;
                return;
            }
            visualizer.generateVisualization(tempoData);
            ui.interactWithVisualization();
        } else {
            cout << "Failed to load file." << endl;
        }
    }