def log_error(self, message, stack_trace, project, module):
        timestamp = get_current_timestamp()
        error = Error(timestamp, message, stack_trace, project, module)
        self.errors.append(error)