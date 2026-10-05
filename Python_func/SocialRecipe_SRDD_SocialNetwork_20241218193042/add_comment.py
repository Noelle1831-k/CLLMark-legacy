def add_comment(self, email, topic, comment):
        if topic not in self.discussions:
            raise ValueError("Discussion topic does not exist.")
        self.discussions[topic]["comments"].append({"author": email, "comment": comment})
        print(f"Comment added to discussion '{topic}' by {email}.")