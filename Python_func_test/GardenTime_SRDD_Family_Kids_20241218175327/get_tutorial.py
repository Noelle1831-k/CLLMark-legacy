def get_tutorial(self, topic):
        print(f"Fetching tutorial for topic: {topic}")
        if topic in self.tutorials:
            print(f"Tutorial content: {self.tutorials[topic]}")
        else:
            print("Tutorial not found. Please choose a valid topic.")