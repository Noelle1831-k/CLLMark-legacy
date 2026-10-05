def list_hunts(self):
        for hunt in self.hunts:
            print(f"Hunt: {hunt.title}, Description: {hunt.description}")