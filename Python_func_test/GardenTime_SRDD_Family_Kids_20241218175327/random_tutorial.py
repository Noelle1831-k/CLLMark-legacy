def random_tutorial(self):
        topic = random.choice(list(self.tutorials.keys()))
        print(f"Random tutorial selected: {topic}")
        print(f"Tutorial content: {self.tutorials[topic]}")