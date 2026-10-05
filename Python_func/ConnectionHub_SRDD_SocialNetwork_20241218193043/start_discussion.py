def start_discussion(self, email, topic):
        if topic not in self.discussions:
            self.discussions[topic] = []
        self.discussions[topic].append(email)
        print(f"Discussion on {topic} started by {email}.")