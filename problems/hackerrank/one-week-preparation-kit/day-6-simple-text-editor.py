#!/bin/python3

def textEditor(operations):
    history = ['']
    for op, *argument in operations:
        if op == '1':
            text = argument[0]
            history.append(history[-1] + text)
        elif op == '2':
            deleted_characters = int(argument[0])
            history.append(history[-1][:-deleted_characters])
        elif op == '3':
            index = int(argument[0]) - 1
            print(history[-1][index])
        else:
            history.pop()

if __name__ == '__main__':
    q = int(input())

    operations = [input().split() for _ in range(q)]

    textEditor(operations)
