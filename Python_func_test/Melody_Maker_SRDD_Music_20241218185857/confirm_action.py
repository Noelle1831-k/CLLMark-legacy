def confirm_action(self, action_description):
        '''
        Asks the user to confirm an action.
        Parameters:
        action_description (str): A description of the action to be confirmed.
        Returns:
        bool: True if the user confirms the action, False otherwise.
        '''
        confirmation = self.get_user_input(f'Are you sure you want to {action_description}? (y/n): ')
        return confirmation.lower() == 'y'