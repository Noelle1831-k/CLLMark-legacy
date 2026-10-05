def display_results(self):
        utils.log_message("Displaying results...")
        self.reporter.highlight_uncovered()
        utils.log_message("Results displayed.")