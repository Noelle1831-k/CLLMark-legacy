def invite_participant(self, participant_username):
        if participant_username not in self.participants:
            self.participants.append(participant_username)