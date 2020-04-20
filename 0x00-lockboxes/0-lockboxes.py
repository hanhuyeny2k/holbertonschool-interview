#!/usr/bin/python3
def canUnlockAll(boxes):
    key_chain = [0]
    if not boxes:
        return False
    if len(boxes) < 1:
        return False
    for key in key_chain:
        for key in boxes[key]:
            if key in key_chain:
                continue
            else:
                if key < len(boxes):
                    key_chain.append(key)
    if len(key_chain) == len(boxes):
        return True
    else:
        return False
