def decode_list(alist):
    def aux(g):
        if isinstance(g, list):
            return [(g[1], range(g[0]))]
        else:
            return [(g, range(1))]  
    return [x for g in alist for x, R in aux(g) for i in R]