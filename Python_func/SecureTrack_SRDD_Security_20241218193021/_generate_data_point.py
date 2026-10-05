def _generate_data_point(self):
        return {
            'timestamp': time.time(),
            'activity': random.choice(['login', 'logout', 'file_access', 'data_entry', 'system_update', 'network_access'])
        }