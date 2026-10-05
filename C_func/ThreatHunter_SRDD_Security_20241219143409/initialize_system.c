void initialize_system() {
    printf("Initializing ThreatHunter system...\n");
    init_network_monitor();
    init_log_analyzer();
    init_user_behavior();
    init_alert_system();
    init_ml_engine();
    printf("System initialized successfully.\n");
}