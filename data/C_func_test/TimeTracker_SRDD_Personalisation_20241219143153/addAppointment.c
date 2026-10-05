void addAppointment(AppointmentManager *manager) {
    if (manager->appointmentCount < MAX_APPOINTMENTS) {
        printf("Enter appointment description: ");
        scanf(" %[^\n]", manager->appointments[manager->appointmentCount].description);
        manager->appointmentCount++;
        printf("Appointment added successfully.\n");
    } else {
        printf("Appointment limit reached. Cannot add more appointments.\n");
    }
}