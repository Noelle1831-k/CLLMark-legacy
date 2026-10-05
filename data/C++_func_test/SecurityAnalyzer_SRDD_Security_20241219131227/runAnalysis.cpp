void SecurityAnalyzer::runAnalysis() {
    cout << "Starting security analysis..." << endl;
    cout << "Analyzing network configurations..." << endl;
    networkScanner.scanPorts();
    networkScanner.checkFirewall();
    networkScanner.evaluateEncryption();
    cout << "Analyzing system settings..." << endl;
    systemScanner.scanSettings();
    systemScanner.detectWeakPasswords();
    systemScanner.checkSecurityFeatures();
    cout << "Analyzing applications..." << endl;
    appScanner.scanApplications();
    appScanner.checkSoftwareUpdates();
    cout << "Analysis complete. Generating report..." << endl;
    reportGen.generateReport();
}