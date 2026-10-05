def export_to_csv(self, data, filename="metrics.csv"):
        """Exports metrics data to a CSV file."""
        try:
            with open(filename, mode="w", newline="") as file:
                writer = csv.writer(file)
                writer.writerow(["Metric", "Value"])
                for key, value in data.items():
                    writer.writerow([key, value])
            print(f"Data exported to {filename} successfully.")
        except Exception as e:
            raise ValueError(f"Error exporting to CSV: {e}")