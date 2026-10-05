def visualize(self, data):
        '''
        Visualizes the data using histograms, scatter plots, and line graphs.
        Parameters:
        - data: DataFrame containing the dataset to be visualized.
        '''
        if data is None or data.empty:
            print("No data available. Please import data first.")
            return
        try:
            print("Visualizing data...")
            self._plot_histograms(data)
            self._plot_scatter_matrix(data)
            self._plot_line_graphs(data)
        except Exception as e:
            print(f"Error visualizing data: {e}")