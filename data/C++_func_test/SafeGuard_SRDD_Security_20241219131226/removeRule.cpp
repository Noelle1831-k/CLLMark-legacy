void removeRule(const string &rule) {
        rules.erase(remove(rules.begin(), rules.end(), rule), rules.end());
        logger->logEvent("Removed firewall rule: " + rule);
    }