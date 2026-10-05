def post_discussion(self, email, topic):
        if topic in self.discussions:
            raise ValueError("Discussion topic already exists.")
        self.discussions[topic] = {"author": email, "comments": []}
        print(f"Discussion '{topic}' posted by {email}.")