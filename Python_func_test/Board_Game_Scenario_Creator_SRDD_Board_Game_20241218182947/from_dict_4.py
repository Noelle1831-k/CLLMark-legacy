def from_dict(cls, data):
        return cls(data["name"], data["position"])