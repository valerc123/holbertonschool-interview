#!/usr/bin/python3
"""
    Check if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
        Returns true if all boxes can be opened
        otherwise returns false
    """
    open_boxes = []
   
    for box in boxes:
        if len(box) > 0:
            for key in box:
                if key and key >= 0:
                    open_boxes.append(key)
        else:
            break
    if 0 not in open_boxes:
        open_boxes.append(0)
    unique_keys = list(set(open_boxes))
    if len(boxes) == len(unique_keys):
        return True
    else:
        return False
