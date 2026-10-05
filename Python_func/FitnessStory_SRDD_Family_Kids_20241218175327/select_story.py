def select_story(self, story_id):
        '''
        Select a story based on the provided story ID.
        Parameters:
        story_id (int): The ID of the story to be selected.
        '''
        if 0 <= story_id < len(self.stories):
            self.selected_story = self.stories[story_id]
            self.ui.display_message(f"Selected story: {self.selected_story.get_title()}")
        else:
            self.ui.display_message("Invalid story selection.")