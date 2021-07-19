#!/usr/bin/python3
""" Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    unlock_boxes = 0
    unlock = [unlock_boxes]
    for index in unlock:
        underbox = boxes[index]
        for indexKeyBox in underbox:
            if indexKeyBox not in unlock and indexKeyBox < len(boxes):
                unlock += [indexKeyBox]
    if len(unlock) == len(boxes):
        return True
    else:
        return False
