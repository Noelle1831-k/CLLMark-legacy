def parse_args(self):
        '''
        Parses command-line arguments for the Data Converter application.
        '''
        parser = argparse.ArgumentParser(description='Data Converter')
        parser.add_argument('input_file', type=str, help='Path to the input file')
        parser.add_argument('output_file', type=str, help='Path to the output file')
        parser.add_argument('--columns', type=str, nargs='+', help='Columns to include in the output')
        parser.add_argument('--rows', type=int, nargs='+', help='Rows to include in the output')
        parser.add_argument('--data_types', type=str, nargs='+', help='Data types for the columns in the format column:type')
        args = parser.parse_args()
        # Validate input and output files
        self.validate_file(args.input_file)
        self.validate_output_file(args.output_file)
        # Parse data_types argument into a dictionary
        if args.data_types:
            args.data_types = self.parse_data_types(args.data_types)
        self.log(f"Arguments parsed successfully: {args}")
        return args