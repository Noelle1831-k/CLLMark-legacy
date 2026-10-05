void removeAppointment(AppointmentManager *manager) {
    int index;
    printf("Enter appointment index to remove: ");
    scanf("%d", &index);
    if (0 <= index && index < manager->appointmentCount) {
        for (int i = index; i < manager->appointmentCount - 1; i++) {
            manager->appointments[i] = manager->appointments[i + 1];
        }
        manager->appointmentCount--;
        printf("Appointment removed successfully.\n");
    } else {
        printf("Invalid appointment index.\n");
    }
}