def get_poll_results(self, question):
        for poll in self.polls:
            if poll["question"] == question:
                return dict(poll.get("votes", {}))
        return {}