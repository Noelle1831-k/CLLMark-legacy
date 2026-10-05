def select_variables(self, variables):
        if self.data is not None:
            try:
                selected_data = self.data[variables]
                print(f"Variables selected: {variables}")
                return selected_data
            except KeyError as e:
                print(f"Error selecting variables: {e}")
                raise
        else:
            raise ValueError("No data imported.")