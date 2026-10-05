def _schedule_reminder(self, reminder):
        now = datetime.datetime.now()
        delay = (reminder['time'] - now).total_seconds()
        if delay > 0:
            threading.Timer(delay, self._send_reminder, args=(reminder,)).start()