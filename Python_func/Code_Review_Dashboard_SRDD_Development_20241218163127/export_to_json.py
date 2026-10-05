def export_to_json(self, data, filename="metrics.json"):
        """Exports metrics data to a JSON file."""
        try:
            with open(filename, mode="w") as file:
                json.dump(data, file, indent=4)
            print(f"Data exported to {filename} successfully.")
        except Exception as e:
            raise ValueError(f"Error exporting to JSON: {e}")