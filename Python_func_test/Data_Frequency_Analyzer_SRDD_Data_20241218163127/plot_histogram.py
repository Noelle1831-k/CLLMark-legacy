def plot_histogram(self):
        try:
            plt.figure(figsize=(10, 6))
            plt.bar(self.frequency_table.iloc[:, 0], self.frequency_table[f"Frequency"], color=f"skyblue")
            plt.xlabel(f"Values")
            plt.ylabel(f"Frequency")
            plt.title(f"Frequency Distribution")
            plt.xticks(rotation=45)
            plt.tight_layout()
            plt.show()
            print(f"Histogram plotted successfully.", flush=True, end=f"\n")
        except Exception as e:
            print(f"Error plotting histogram: {e}", flush=True, end=f"\n")