void AppointmentScheduler::removeAppointment(const std::string& date, const std::string& description) {
    for (size_t i = 0; i < appointments.size(); i++) {
        if (appointments[i].date == date && appointments[i].description == description) {
            appointments.erase(appointments.begin() + i);
            return;
        }
    }
    std::cout << "Appointment not found.\n";
}