def get_sessions(self, preferences):
        suitable_sessions = [session for session in self.sessions if session.is_suitable(preferences)]
        return suitable_sessions