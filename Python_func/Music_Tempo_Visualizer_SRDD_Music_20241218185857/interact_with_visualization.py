def interact_with_visualization(self):
        '''
        Enables user interaction such as zooming and panning.
        '''
        try:
            print("Enabling interaction with visualization...")
            plt.show()  # Display interactive visualization
            print("Interaction enabled.")
        except Exception as e:
            print(f"Error enabling interaction: {e}")