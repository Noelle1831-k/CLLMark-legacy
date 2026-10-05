def update_tutorial(self, topic, content):
        if topic in self.tutorials:
            self.tutorials[topic] = content
            print(f"Updated tutorial for topic: {topic}")
        else:
            print("Tutorial not found. Please add the tutorial first.")