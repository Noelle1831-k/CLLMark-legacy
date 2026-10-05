def start_story(self):
        '''
        Start the selected story and guide the user through the activities.
        '''
        if self.selected_story:
            self.ui.display_story(self.selected_story)
            for activity in self.selected_story.get_activities():
                self.ui.display_activity(activity)
                self.ui.display_message('Follow the instructions and perform the activity.')
                self.ui.display_message(activity.get_instructions())
                self.ui.display_message(f'Watch the demo: {activity.get_demo_url()}')
                self.ui.get_user_input('Press Enter to continue to the next activity...')