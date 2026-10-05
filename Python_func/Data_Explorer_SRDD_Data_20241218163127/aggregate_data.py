def aggregate_data(self, operations):
        # Aggregate the grouped data using specified operations
        if self.grouped_data is not None:
            self.data = self.grouped_data.agg(operations).reset_index()
        else:
            raise ValueError("Data must be grouped before aggregation.")