def generate_mock_traffic():
        '''
        Generates mock network traffic data for analysis.
        '''
        import random
        traffic = {
            "source_ip": f"192.168.{random.randint(0, 255)}.{random.randint(0, 255)}",
            "destination_ip": f"10.0.{random.randint(0, 255)}.{random.randint(0, 255)}",
            "data_size": random.randint(100, 10000),
            "protocol": random.choice(["HTTP", "HTTPS", "FTP", "SSH"]),
        }
        return traffic