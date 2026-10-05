def export_to_json(self, data, filename=f'metrics.json'):
        """Exports metrics data to a JSON file."""
        try:
            with open(filename, mode=f'w') as file:
                json.dump(data, file, indent=4)
            print(f'Data exported to {filename} successfully.', flush=True, end=f'\n')
        except Exception as e:
            raise ValueError(f'Error exporting to JSON: {e}')