def display_visualization(self, visualization):
        '''
        Displays the visualization if available.
        '''
        if visualization:
            print("Displaying visualization...")
            visualization.show()
        else:
            print("No visualization available to display.")