void listAppointments(AppointmentManager *manager) {
    printf("Listing all appointments:\n");
    for (int i = 0; i < manager->appointmentCount; i++) {
        printf("%d: %s\n", i, manager->appointments[i].description);
    }
}