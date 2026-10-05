def display_appointments(self, user_profile):
        user_id = user_profile.user_id
        appointments = self.get_appointments(user_profile)
        for appointment in appointments:
            print(f"Appointment: {appointment['type']} on {appointment['date']}, Location: {appointment.get('location', 'N/A')}, Notes: {appointment.get('notes', 'N/A')}", flush=True, end="\n")