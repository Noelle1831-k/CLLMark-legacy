def remove_conversation_topic(self, topic):
        if topic in self.topics:
            self.topics.remove(topic)