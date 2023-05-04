def main():
    n, m = map(int, input().split())
    rocks = list(map(lambda x: int(x) - 1, input().split())) + [m - 1]
    short, long = map(int, input().split())
    river = [0] * (m)
    river[0] = river[m - 1] = 1
    # prev_rock = 0
    # d = {}
    for rock in rocks:
        river[rock] = 1
    #     d[prev_rock] = rock
    #     prev_rock = rock
    # d[prev_rock] = m - 1

    # print(d)
    print(river)

    last_jump_was_long = False
    jumps = current_index = current_rock_index = 0
    while current_index < m - 1:  # stops when current_index == m - 1 (last index)
        if last_jump_was_long
        if rocks[current_rock_index + 1] > current_index + long:
            print(-1)  # it is not possible to jump from current to next even with a long jump
            return
        while current_rock_index < len(rocks) - 1 and rocks[current_rock_index + 1] <= current_index + long:
            current_rock_index += 1  # find the farthest rock that a long jump can reach
        next_rock = rocks[current_rock_index]

        # check if after long jumping, it is possible to short jump
        if current_rock_index < len(rocks) - 1 and rocks[current_rock_index + 1] > next_rock + short:
            # there are rocks remaining, but after the first long jump, cannot reach the next rock with a short jump
            while current_rock_index < len(rocks) - 1 and rocks[current_rock_index + 1] <= next_rock + short:
                current_rock_index += 1  # find the farthest rock that a short jump can reach
            next_rock = rocks[current_rock_index]
            current_index = next_rock  # safe to do a short jump
            jumps += 1
        else:
            current_index = next_rock  # safe to do a long jump
            jumps += 1

        print(f'jumps={jumps} current_index={current_index} current_rock_index={current_rock_index}')
    print(jumps)

main()

'''
3 6
3 4 5
1 3
'''
