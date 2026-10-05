def parse_data_types(self, data_types):
        '''
        Parses the data types argument into a dictionary.
        '''
        data_types_dict = {}
        pattern = re.compile(r"(\w+):(\w+)")
        for data_type in data_types:
            match = pattern.match(data_type)
            if match:
                column, dtype = match.groups()
                data_types_dict[column] = dtype
            else:
                self.log(f"Invalid data type format: {data_type}")
                raise ValueError(f"Invalid data type format: {data_type}")
        self.log(f"Data types parsed successfully: {data_types_dict}")
        return data_types_dict