void SecurityMonitor::scanFiles(ThreatHandler &handler, Logger &logger) {
    vector<string> files = {"file1.txt", "file2.exe", "malware.exe"};
    for (size_t i = 0; i < files.size(); i++) {
        if (files[i].find("malware") != string::npos) {
            logger.log("Suspicious file detected: " + files[i]);
            handler.handleThreat("File: " + files[i]);
        }
    }
}