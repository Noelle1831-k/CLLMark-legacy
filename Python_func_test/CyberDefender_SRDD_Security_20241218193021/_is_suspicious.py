def _is_suspicious(self, packet):
        return packet["data"] > 900