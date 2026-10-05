def display_visualizations(self, charts):
        '''
        Display the generated visualizations.
        '''
        if charts is None:
            return
        try:
            plt.bar(charts['moods'], charts['counts'])
            plt.xlabel('Mood')
            plt.ylabel('Count')
            plt.title('Mood Analysis Results')
            plt.show()
        except Exception as e:
            print(f"Error displaying visualizations: {e}", flush=True)