def post_reply(self, topic, email, reply):
        if topic in self.discussions:
            self.discussions[topic].append((email, reply))
            print(f"Reply posted by {email} in discussion {topic}.")
        else:
            print("Discussion not found.")