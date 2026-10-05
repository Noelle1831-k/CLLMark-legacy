void addRule(const string &rule) {
        rules.push_back(rule);
        logger->logEvent("Added firewall rule: " + rule);
    }