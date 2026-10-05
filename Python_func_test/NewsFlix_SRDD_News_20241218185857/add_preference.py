def add_preference(self, topic):
        '''
        Adds a new topic to the preferences list if it is not already present.
        '''
        if topic not in self.preferences:
            self.preferences.append(topic)
            print(f"Added preference: {topic}")
        else:
            print(f"Preference '{topic}' already exists.")