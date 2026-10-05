bool ThreatClassifier::detectThreat() {
    cout << "Classifying potential threats..." << endl;
    Utils::logMessage("Threat classification started.");
    bool threatDetected = rand() % 2 == 0;
    Utils::logMessage(threatDetected ? "Threat detected." : "No threat detected.");
    return threatDetected;
}