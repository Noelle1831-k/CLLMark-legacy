def _generate_random_log(self):
        return {
            "timestamp": random.randint(1609459200, 1630995200),
            "event": random.choice(["login", "logout", "file_access", "error"]),
            "user": f"user{random.randint(1, 10)}"
        }