def get_lesson(self, topic):
        """Retrieve a lesson on a specific music theory topic."""
        if topic.lower() in self.lessons:
            return self.lessons[topic.lower()]
        else:
            # Return a random lesson if the topic is unknown.
            random_topic = random.choice(list(self.lessons.keys()))
            return f"Lesson on {random_topic}:\n{self.lessons[random_topic]}"