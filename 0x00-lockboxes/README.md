# Lockboxes

## Requirements
* Allowed editors: vi, vim, emacs
* All the files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)
* All the files should end with a new line
* The first line of all the files should be exactly #!/usr/bin/python3
* A README.md file, at the root of the folder of the project, is mandatory
* The code should use the PEP 8 style (version 1.7.x)
* All the files must be executable

## Tasks
You have n number of locked boxes in front of you. Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.

* Prototype: def canUnlockAll(boxes)
* boxes is a list of lists
* A key with the same number as a box opens that box
* You can assume all keys will be positive integers
* The first box boxes[0] is unlocked
* Return True if all boxes can be opened, else return False
