def display_results(self, formatted_output):
        '''
        Displays the results to the user.
        '''
        print(self.result_header, end='\n')
        print(formatted_output, end='\n')