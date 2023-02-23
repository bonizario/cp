#!/bin/python3

import math
import os
import random
import re
import sys

def noPrefix(words):
    root = {}
    for word in words:
        visited_characters = root
        for j, character in enumerate(word):
            if character not in visited_characters:
                visited_characters[character] = {}  # passed by reference
            visited_characters = visited_characters[character]
            if '*' in visited_characters or (j == len(word) - 1 and visited_characters):
                print("BAD SET\n", word, sep = '')
                return
        visited_characters['*'] = True
    print('GOOD SET')

if __name__ == '__main__':
    n = int(input().strip())

    words = []

    for _ in range(n):
        words_item = input()
        words.append(words_item)

    noPrefix(words)
