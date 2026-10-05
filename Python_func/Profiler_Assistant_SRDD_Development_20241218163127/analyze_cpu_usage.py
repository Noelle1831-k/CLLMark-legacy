def analyze_cpu_usage(self, data):
        print("Analyzing CPU usage...")
        return [entry['cpu_usage'] for entry in data]