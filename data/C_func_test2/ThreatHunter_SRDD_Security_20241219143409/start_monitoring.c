void start_monitoring() {
    printf("Starting monitoring...\n");
    while (!stop) {
        monitor_network();
        analyze_logs();
        analyze_user_behavior();
        run_ml_engine();
        sleep(1); 
    }
    printf("Monitoring stopped.\n");
}