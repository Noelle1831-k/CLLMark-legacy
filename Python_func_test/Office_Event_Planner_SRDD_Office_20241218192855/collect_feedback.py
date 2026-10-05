def collect_feedback(self):
        if self.events:
            for attendee in self.events[-1].attendees:
                if attendee.rsvp_status == "Accepted":
                    feedback = Feedback(attendee, "Great event!", random.randint(1, 5))
                    self.events[-1].feedback.append(feedback)