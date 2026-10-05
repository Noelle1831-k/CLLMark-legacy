void run() {
        logger.log("Running ShieldGuard...");
        while (isRunning) {
            threatDetector.monitor();
            secureBrowser.monitor();
            logger.log("ShieldGuard is active...");
        }
    }