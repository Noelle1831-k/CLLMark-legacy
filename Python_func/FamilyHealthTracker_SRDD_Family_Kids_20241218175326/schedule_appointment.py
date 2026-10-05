def schedule_appointment(self, user_profile, appointment_type, date, location=None, notes=None):
        user_id = user_profile.user_id
        if user_id not in self.appointments:
            self.appointments[user_id] = []
        self.appointments[user_id].append({
            "type": appointment_type,
            "date": date,
            "location": location,
            "notes": notes
        })