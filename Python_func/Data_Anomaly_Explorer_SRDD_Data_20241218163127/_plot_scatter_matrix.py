def _plot_scatter_matrix(self, data):
        '''
        Plots a scatter matrix for the dataset to visualize pairwise relationships.
        Parameters:
        - data: DataFrame containing the dataset to be visualized.
        '''
        print("Plotting scatter matrix...")
        num_cols = data.select_dtypes(include=['float64', 'int64']).columns
        pd.plotting.scatter_matrix(data[num_cols], figsize=(15, 15), diagonal='kde')
        plt.suptitle('Scatter Matrix of Numerical Features', fontsize=16)
        plt.show()