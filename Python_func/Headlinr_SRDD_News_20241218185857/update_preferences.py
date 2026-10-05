def update_preferences(self):
        # Prompt user for topics
        topics_input = input("Enter your preferred topics, separated by commas: ")
        self.topics = [topic.strip() for topic in topics_input.split(',')]
        # Prompt user for sources
        sources_input = input("Enter your preferred sources, separated by commas: ")
        self.sources = [source.strip() for source in sources_input.split(',')]