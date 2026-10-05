def add_session(self, session):
        if not isinstance(session, MeditationSession):
            raise TypeError("Invalid session type.")
        self.sessions.append(session)