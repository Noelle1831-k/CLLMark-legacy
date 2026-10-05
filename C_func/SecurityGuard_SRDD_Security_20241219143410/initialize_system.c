void initialize_system() {
    printf("Initializing SecurityGuard system...\n");
    initialize_scan_module();
    initialize_alerts_module();
    initialize_secure_browsing();
    initialize_password_manager();
    initialize_utils();  
    printf("System initialized successfully!\n");
}