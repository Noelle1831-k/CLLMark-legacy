def process_interaction(self):
        if self.interaction_type == "like":
            self.content.add_like()
        elif self.interaction_type == "comment" and self.comment:
            self.content.add_comment(self.comment)
        else:
            raise ValueError("Invalid interaction type")