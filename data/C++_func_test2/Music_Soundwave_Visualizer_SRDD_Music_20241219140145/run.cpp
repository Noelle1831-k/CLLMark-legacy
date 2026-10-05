void run() {
        cout << "Welcome to the Music Soundwave Visualizer!" << endl;
        cout << "Please enter the path to your audio file: ";
        string filepath;
        cin >> filepath;
        if (!audioProcessor.loadFile(filepath)) {
            cerr << "Error: Unable to load the specified file." << endl;
            return;
        }
        audioProcessor.decodeAudio();
        vector<float> soundwaveData = audioProcessor.extractSoundwaveData();
        visualizer.initializeGraphics();
        visualizer.renderWaveform(soundwaveData);
        string command;
        while (true) {
            cout << "Enter a command (zoom, pan, rotate, quit): ";
            cin >> command;
            if (command == "zoom") {
                string zoomType;
                cout << "Enter 'in' or 'out': ";
                cin >> zoomType;
                if (zoomType == "in") {
                    userInteraction.zoomIn();
                } else if (zoomType == "out") {
                    userInteraction.zoomOut();
                }
            } else if (command == "pan") {
                float x, y;
                cout << "Enter pan values (x y): ";
                cin >> x >> y;
                userInteraction.pan(x, y);
            } else if (command == "rotate") {
                float angle;
                cout << "Enter rotation angle: ";
                cin >> angle;
                userInteraction.rotate(angle);
            } else if (command == "quit") {
                break;
            } else {
                cout << "Invalid command!" << endl;
            }
        }
        cout << "Thank you for using the Music Soundwave Visualizer!" << endl;
    }