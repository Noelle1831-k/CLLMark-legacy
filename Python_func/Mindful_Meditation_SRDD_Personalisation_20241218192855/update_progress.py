def update_progress(self, session):
        if not isinstance(session, MeditationSession):
            raise TypeError("Invalid session type.")
        self.sessions_completed += 1
        self.total_duration += session.duration