def remove_preference(self, topic):
        '''
        Removes a topic from the preferences list if it exists.
        '''
        if topic in self.preferences:
            self.preferences.remove(topic)
            print(f"Removed preference: {topic}")
        else:
            print(f"Preference '{topic}' not found.")