def capture_traffic(self):
        # Simulate capturing network traffic with more complex data patterns
        traffic_data = [random.randint(0, 100) for _ in range(100)]
        # Add simulated packet metadata
        metadata = [{'source_ip': f"192.168.1.{random.randint(1, 255)}", 'dest_ip': f"10.0.0.{random.randint(1, 255)}"} for _ in range(100)]
        return list(zip(traffic_data, metadata))