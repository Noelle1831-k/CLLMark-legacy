def run(self):
        args = self.utils.parse_args()
        self.load_file(args.input_file)
        self.convert_data(args)
        self.save_file(args.output_file)