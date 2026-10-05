def start_discussion(self, event, topic):
        discussion = Discussion(event, topic)
        self.discussions.append(discussion)
        return discussion