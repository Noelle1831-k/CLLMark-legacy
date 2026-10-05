def _generate_random_packet(self):
        return {
            "source": f"192.168.1.{random.randint(1, 255)}",
            "destination": f"192.168.1.{random.randint(1, 255)}",
            "data": random.randint(0, 1000)
        }