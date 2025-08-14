#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""Documentation of the lockboxes module"""


def canUnlockAll(boxes):
    """
    Check if all boxes can be opened.

    Args:
        boxes (a list of lists): contain keys to the other boxes

    Returns:
        boolean: True if all boxes can be opened, else return False
    """
    unlocked = [0]
    for box_id, box in enumerate(boxes):
        if not box:
            continue
        for value in box:
            if (
                value < len(boxes)
                and value not in unlocked
                and value != box_id
            ):
                unlocked.append(value)
    if len(unlocked) == len(boxes):
        return True
    return False
