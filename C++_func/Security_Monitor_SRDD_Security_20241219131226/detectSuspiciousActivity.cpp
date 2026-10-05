bool NetworkMonitor::detectSuspiciousActivity() {
    int randomValue = rand() % 100;
    return randomValue < 10; 
}