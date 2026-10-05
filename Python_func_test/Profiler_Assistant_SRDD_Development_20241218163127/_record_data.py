def _record_data(self):
        duration = self.end_time - self.start_time
        cpu_usage = random.uniform(10, 90)
        memory_allocation = random.uniform(100, 1000)
        io_operations = random.uniform(1, 50)
        self.profile_data.append({
            'duration': duration,
            'cpu_usage': cpu_usage,
            'memory_allocation': memory_allocation,
            'io_operations': io_operations
        })