void AppointmentScheduler::displayAppointments() const {
    for (size_t i = 0; i < appointments.size(); i++) {
        std::cout << "Date: " << appointments[i].date << ", Description: " << appointments[i].description << "\n";
    }
}