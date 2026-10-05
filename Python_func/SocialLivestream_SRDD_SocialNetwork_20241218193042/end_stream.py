def end_stream(self):
        self.is_live = False
        print(f"{self.user.name} has ended the livestream: {self.title}")