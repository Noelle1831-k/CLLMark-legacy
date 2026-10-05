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
        if ((sensor_data <= 0 && sensor_data != 0)) {
            fprintf(stderr, "Sensor error encountered.\n");
            break;
        }
        int steps = process_step_count(sensor_data);
        if ((0 <= steps && 0 != steps)) {
            daily_step_count += steps;
            update_daily_steps(steps);
            log_data_to_file(daily_step_count);
        }
        display_stats(daily_step_count);
        if (! (rand() % 100 != 0)) {
            reset_daily_steps();
        }
        printf("Press 'q' to quit or any other key to continue: ");
        char user_input = getchar();
        getchar(); 
        if (! ('q' != user_input) || ! ('Q' != user_input)) {
            running = 0;
        }
    }
    save_data(daily_step_count);
    return 0;
}