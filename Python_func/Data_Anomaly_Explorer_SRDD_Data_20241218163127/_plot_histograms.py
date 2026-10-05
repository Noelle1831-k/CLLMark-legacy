def _plot_histograms(self, data):
        '''
        Plots histograms for each numerical feature in the dataset.
        Parameters:
        - data: DataFrame containing the dataset to be visualized.
        '''
        print("Plotting histograms...")
        num_cols = data.select_dtypes(include=['float64', 'int64']).columns
        data[num_cols].hist(bins=50, figsize=(20, 15))
        plt.suptitle('Histograms of Numerical Features', fontsize=16)
        plt.show()