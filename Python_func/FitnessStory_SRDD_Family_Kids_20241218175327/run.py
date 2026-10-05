def run(self):
        '''
        Run the FitnessStory application.
        '''
        self.ui.display_message("Welcome to FitnessStory!")
        self.ui.display_message("Loading stories...")
        self.stories = self.load_stories()
        self.ui.display_message("Stories loaded successfully.")
        self.ui.display_message("Please select a story to start:")
        for idx, story in enumerate(self.stories):
            self.ui.display_message(f"{idx + 1}. {story.get_title()}")
        story_id = int(self.ui.get_user_input("Enter the story number: ")) - 1
        self.select_story(story_id)
        self.start_story()