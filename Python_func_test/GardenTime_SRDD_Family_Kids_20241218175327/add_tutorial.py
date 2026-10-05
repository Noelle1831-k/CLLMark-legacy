def add_tutorial(self, topic, content):
        if topic not in self.tutorials:
            self.tutorials[topic] = content
            print(f"Added new tutorial for topic: {topic}")
        else:
            print("Tutorial already exists. Use update_tutorial to modify existing content.")