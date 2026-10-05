def schedule(self, test_suite, execution_time):
        delay = self._calculate_delay(execution_time)
        task = threading.Timer(delay, test_suite.execute)
        self.scheduled_tasks.append(task)
        task.start()