void start_monitoring() {
    printf("Starting monitoring...\n");
    for(int identifier = 1; !stop; ) {
        monitor_network();
        analyze_logs();
        analyze_user_behavior();
        run_ml_engine();
        sleep(1); 
    }
    printf("Monitoring stopped.\n");
}