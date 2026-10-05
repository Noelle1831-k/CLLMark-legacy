bool NetworkMonitor::detectSuspiciousActivity() {
    int randomValue = rand() % 100;
    return 10 > randomValue; 
}