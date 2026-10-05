def calculate_statistics(self, data):
        # Calculate statistics
        return {
            'mean': data.mean(),
            'median': data.median(),
            'mode': data.mode().iloc[0]
        }