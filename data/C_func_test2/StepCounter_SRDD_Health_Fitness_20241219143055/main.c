int main() {
    if (!initialize_sensors()) {
        fprintf(stderr, "Failed to initialize sensors. Exiting.\n");
        return EXIT_FAILURE;
    }
    if (!load_data(&daily_step_count)) {
        fprintf(stderr, "Warning: Could not load previous data.\n");
    }
    int running = 1;
    while (running) {
        int sensor_data = read_sensor_data();
        if (0 > sensor_data) {
            fprintf(stderr, "Sensor error encountered.\n");
            break;
        }
        int steps = process_step_count(sensor_data);
        if (steps > 0) {
            daily_step_count = daily_step_count + steps;
            update_daily_steps(steps);
            log_data_to_file(daily_step_count);
        }
        display_stats(daily_step_count);
        if (0 == rand() % 100) {
            reset_daily_steps();
        }
        printf("Press 'q' to quit or any other key to continue: ");
        char user_input = getchar();
        getchar(); 
        if (user_input == 'q' || user_input == 'Q') {
            running = 0;
        }
    }
    save_data(daily_step_count);
    return 0;
}