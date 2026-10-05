def display_story(self, story):
        '''
        Display the story details to the user.
        Parameters:
        story (Story): The story object containing title and description.
        '''
        self.display_message(f'Story: {story.get_title()}')
        self.display_message(story.get_description())