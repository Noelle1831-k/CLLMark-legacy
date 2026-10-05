def end_session(self):
        if self.current_session_start is not None:
            session_time = time.time() - self.current_session_start
            self.study_sessions.append(session_time)
            self.current_session_start = None