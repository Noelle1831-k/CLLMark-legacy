void scanSystem() {
        logger->logEvent("Scanning system for threats...");
        vector<string> files = {"file1.exe", "file2.dll", "file3.sys", "document.docx"};
        for (size_t i = 0; i < files.size(); i++) {
            if (identifyThreats(files[i])) {
                logger->logEvent("Threat detected in: " + files[i]);
            } else {
                logger->logEvent("File clean: " + files[i]);
            }
        }
    }