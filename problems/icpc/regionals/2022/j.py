def main():
    def get_cards():
        cards = input().replace('11', '10').replace('12', '10').replace('13', '10')
        return tuple(map(int, cards.split()))

    def get_points(hand, board):
        points = {i: i for i in range(1, 11)}
        points[11] = points[12] = points[13] = 10
        return sum(map(lambda x: points[x], hand + board))

    n = int(input())
    j = get_cards()
    m = get_cards()
    board = get_cards()
    cards = {i: 0 for i in range(1, 14)}
    for card in (j + m + board):
        cards[card] += 1
    j_points = get_points(j, board)
    m_points = get_points(m, board)
    ans = -1
    if m_points >= j_points:
        win_card = 23 - m_points
        if win_card <= 10 and ((win_card == 10 and cards[win_card] < 16) or cards[win_card] < 4):
            ans = win_card
    else:
        for i in range(11):
            win_card = 24 - j_points + i
            if cards[win_card] < 4:
                break
        if win_card <= 10 and m_points + win_card <= 23:
            ans = win_card
    print(ans)
main()
