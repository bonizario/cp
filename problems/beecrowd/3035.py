def main():
    from collections import defaultdict

    pieces = defaultdict(int)
    compound_pieces = defaultdict(list)

    def price(piece):
        if piece in pieces:
            return pieces[piece]
        total = 0
        for subpiece, quantity in compound_pieces[piece]:
            if subpiece in pieces:
                total += (pieces[subpiece] * quantity)
            else:
                total += (price(subpiece) * quantity)
        pieces[piece] = total
        return total

    for _ in range(int(input())):
        piece, cost = input().split()
        pieces[piece] = int(cost)

    while True:
        try:
            p1, p2, p2_quantity = input().split()
        except:
            break
        compound_pieces[p1].append([p2, int(p2_quantity)])
    '''
    compound_pieces = {'D': [['A', 2]],
                       'E': [['D', 1], ['A', 4]],
                       'F': [['E', 3], ['B', 10]]}
    '''

    for compound_piece in compound_pieces:
        print(f'{compound_piece} {price(compound_piece)}')

main()
