void applyRules() {
        logger->logEvent("Applying firewall rules...");
        for (size_t i = 0; i < rules.size(); i++) {
            logger->logEvent("Enforcing rule: " + rules[i]);
        }
    }