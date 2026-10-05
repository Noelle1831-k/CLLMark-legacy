int process_step_count(int sensor_data) {
    if (sensor_data > STEP_THRESHOLD) {
        return 1; 
    }
    return 0; 
}