def main():
    cards = {1: 4, 2: 4, 3: 4, 4: 4, 5: 4, \
             6: 4, 7: 4, 8: 4, 9: 4, 10: 16}
    value = {1: 1, 2: 2, 3: 3, 4: 4, 5: 5, 6: 6, 7: 7, \
             8: 8, 9: 9, 10: 10, 11: 10, 12: 10, 13: 10}

    n = int(input())
    john = list(map(int, input().split()))
    mary = list(map(int, input().split()))
    pile = list(map(int, input().split()))

    for drawn in john + mary + pile:
        cards[value[drawn]] -= 1

    total_pile = sum(value[card] for card in pile)
    total_john = sum(value[card] for card in john) + total_pile
    total_mary = sum(value[card] for card in mary) + total_pile

    mary_winning_card = 23 - total_mary
    john_losing_card = 24 - total_john
    while john_losing_card <= 10 and cards[john_losing_card] == 0:
        john_losing_card += 1

    mary_can_win = mary_winning_card <= 10 and cards[mary_winning_card] >= 1
    john_can_lose = john_losing_card <= 10
    mary_loses_if_john_loses = total_mary + john_losing_card > 23

    if mary_can_win:
        if john_can_lose and not mary_loses_if_john_loses:
            print(min(mary_winning_card, john_losing_card))
        else:
            print(mary_winning_card)
    elif john_can_lose and not mary_loses_if_john_loses:
        print(john_losing_card)
    else:
        print('-1')

main()
