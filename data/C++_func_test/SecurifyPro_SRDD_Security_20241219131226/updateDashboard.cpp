void MainWindow::updateDashboard() {
    netAnalyzer.analyzeTraffic();
    logAnalyzer.scanLogs();
    userAnalyzer.monitorBehavior();
    threatNeutralizer.scanAndNeutralize();
    displayAlert("System scan completed.");
}