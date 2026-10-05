def remove_tutorial(self, topic):
        if topic in self.tutorials:
            del self.tutorials[topic]
            print(f"Removed tutorial for topic: {topic}")
        else:
            print("Tutorial not found.")