void loadData() {
    FILE *file = fopen("vacation_requests.dat", "rb");
    if (file == NULL) {
        printf("No existing data found. Starting fresh.\n");
        return;
    }
    requestCount = fread(vacationRequests, sizeof(VacationRequest), MAX_REQUESTS, file);
    fclose(file);
    printf("Data loaded successfully.\n");
}