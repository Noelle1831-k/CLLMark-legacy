def aggregate_rows(self, data, operations):
        # Aggregate rows using specified operations
        return data.agg(operations)