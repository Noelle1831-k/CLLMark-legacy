def display_visualization(self, visualization):
        '''
        Displays the visualization if available.
        '''
        if visualization:
            print(f'Displaying visualization...', flush=True, end=f'\n')
            visualization.show()
        else:
            print(f'No visualization available to display.', flush=True, end=f'\n')