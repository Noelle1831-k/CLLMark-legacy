def get_appointments(self, user_profile):
        user_id = user_profile.user_id
        return self.appointments.get(user_id, [])