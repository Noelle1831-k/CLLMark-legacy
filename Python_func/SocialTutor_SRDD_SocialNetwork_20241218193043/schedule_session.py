def schedule_session(self, tutor, student, subject, time):
        # Validate tutor and student
        if tutor not in self.users or student not in self.users:
            raise ValueError("Tutor or student not found.")
        # Validate time format (simple example, extend as needed)
        if not re.match("^[A-Za-z]+ \d{1,2} [AP]M$", time):
            raise ValueError("Invalid time format. Please use 'Day HH AM/PM' format.")
        session = Session(tutor, student, subject, time)
        self.sessions.append(session)
        self.database.add_session(session)
        return session