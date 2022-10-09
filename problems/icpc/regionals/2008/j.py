# unfair coin flipping https://en.wikipedia.org/wiki/Gambler's_ruin
def main():
    from math import ceil
    while True:
        ev1, ev2, at, d = map(int, input().split())
        if ev1 == ev2 == at == d == 0:
            break
        ev1, ev2 = ceil(ev1/d), ceil(ev2/d)
        p = at / 6
        q = 1 - p
        if at == 3:
            prob = ev1/(ev1 + ev2)
        else:
            prob = (1 - (q/p)**ev1) / (1 - (q/p)**(ev1+ev2))
        print(f'{100 * prob:.1f}')
main()
