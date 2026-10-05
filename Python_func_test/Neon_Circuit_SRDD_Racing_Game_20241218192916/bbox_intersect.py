def bbox_intersect(self, bbox1, bbox2):
        # Check if two bounding boxes intersect
        return (bbox1[0] < bbox2[2] and bbox1[2] > bbox2[0] and
                bbox1[1] < bbox2[3] and bbox1[3] > bbox2[1])