#!/usr/bin/python3
'''
    return key pf boxes
'''


def canUnlockAll(boxes):
    ''' num_boxes = len(boxes)'''
    open_boxes = []

    for box in boxes:
        if len(box) > 0:
            for key in box:
                if key & key >= 0:
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
