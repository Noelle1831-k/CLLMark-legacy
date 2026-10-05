def increment_vote(self, question, option):
        for poll in self.polls:
            if poll["question"] == question:
                if "votes" not in poll:
                    poll["votes"] = defaultdict(int)
                poll["votes"][option] += 1