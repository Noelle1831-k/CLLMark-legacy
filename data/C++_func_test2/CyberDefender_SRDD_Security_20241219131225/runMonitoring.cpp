void runMonitoring(NetworkMonitor& networkMonitor, SystemLogMonitor& logMonitor, AIEngine& aiEngine, AlertManager& alertManager) {
    while (true) {
        networkMonitor.analyzeTraffic();
        logMonitor.analyzeLogs();
        aiEngine.detectThreats();
        alertManager.sendAlert();
        alertManager.neutralizeThreat();
        this_thread::sleep_for(chrono::seconds(1)); 
    }
}