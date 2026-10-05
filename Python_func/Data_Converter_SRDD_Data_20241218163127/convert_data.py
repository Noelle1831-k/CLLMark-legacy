def convert_data(self, args):
        self.data = self.data_converter.convert(self.data, args.columns, args.rows, args.data_types)