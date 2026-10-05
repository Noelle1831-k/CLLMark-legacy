void AppointmentScheduler::addAppointment(const std::string& date, const std::string& description) {
    Appointment newAppointment = {date, description};
    appointments.push_back(newAppointment);
}