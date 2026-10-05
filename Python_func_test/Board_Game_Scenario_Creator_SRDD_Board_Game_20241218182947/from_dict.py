def from_dict(cls, data):
        setup = cls(data["dimensions"])
        setup.layout = data["layout"]
        return setup