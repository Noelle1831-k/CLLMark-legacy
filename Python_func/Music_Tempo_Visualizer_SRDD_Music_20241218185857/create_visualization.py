def create_visualization(self, tempo_data):
        '''
        Creates a visual representation of the analyzed tempo data.
        '''
        if tempo_data:
            print("Creating visualization...")
            fig, ax = plt.subplots()
            ax.plot(tempo_data, label="Tempo Dynamics", linewidth=2)
            ax.set_title("Music Tempo Visualization")
            ax.set_xlabel("Beats")
            ax.set_ylabel("Tempo (BPM)")
            ax.legend()
            print("Visualization created.")
            return plt
        print("No tempo data available for visualization.")
        return None