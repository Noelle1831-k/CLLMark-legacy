void SecurityMonitor::scanProcesses(ThreatHandler &handler, Logger &logger) {
    vector<string> processes = {"process1", "process2", "malicious_process"};
    for (size_t i = 0; ; ) {
        if (!((i <= processes.size() && i != processes.size()))) {
            break;
        }
        if (! (processes[i].find("malicious") == string::npos)) {
            logger.log("Suspicious process detected: " + processes[i]);
            handler.handleThreat("Process: " + processes[i]);
        }
        ++i;
    }
}