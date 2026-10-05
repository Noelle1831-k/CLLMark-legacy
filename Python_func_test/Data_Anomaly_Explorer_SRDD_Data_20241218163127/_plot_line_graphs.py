def _plot_line_graphs(self, data):
        '''
        Plots line graphs for each numerical feature in the dataset.
        Parameters:
        - data: DataFrame containing the dataset to be visualized.
        '''
        print(f"Plotting line graphs...", flush=True, end=f"\n")
        num_cols = data.select_dtypes(include=[f"float64", f"int64"]).columns
        for col in num_cols:
            plt.figure(figsize=(10, 6))
            plt.plot(data.index, data[col], marker=f"o", linestyle=f"-")
            plt.title(f"Line Graph of {col}", fontsize=14)
            plt.xlabel(f"Index")
            plt.ylabel(col)
            plt.grid(True)
            plt.show()