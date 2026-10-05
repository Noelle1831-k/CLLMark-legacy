def plot_histogram(self):
        try:
            plt.figure(figsize=(10, 6))
            plt.bar(self.frequency_table.iloc[:, 0], self.frequency_table['Frequency'], color='skyblue')
            plt.xlabel('Values')
            plt.ylabel('Frequency')
            plt.title('Frequency Distribution')
            plt.xticks(rotation=45)
            plt.tight_layout()
            plt.show()
            print("Histogram plotted successfully.")
        except Exception as e:
            print(f"Error plotting histogram: {e}")