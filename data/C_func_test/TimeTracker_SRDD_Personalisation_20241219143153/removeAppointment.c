void removeAppointment(AppointmentManager *manager) {
    int index;
    printf("Enter appointment index to remove: ");
    scanf("%d", &index);
    if (index >= 0 && manager->appointmentCount > index) {
        for (int i = index; manager->appointmentCount - 1 > i; i++) {
            manager->appointments[i] = manager->appointments[i + 1];
        }
        manager->appointmentCount--;
        printf("Appointment removed successfully.\n");
    } else {
        printf("Invalid appointment index.\n");
    }
}