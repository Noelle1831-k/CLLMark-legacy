def find_group_by_topic(self, topic):
        if not topic:
            raise ValueError("Topic must be a non-empty string.")
        return [group for group in self.groups if group.topic == topic]