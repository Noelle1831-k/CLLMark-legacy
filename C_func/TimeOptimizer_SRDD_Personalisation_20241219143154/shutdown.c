void shutdown() {
    if (!is_running) {
        log_message("Application is already shut down.");
        return;
    }
    log_message("Shutting down application...");
    save_data();
    is_running = 0;
    log_message("Shutdown complete.");
}