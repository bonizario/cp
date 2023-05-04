def main():
    for _ in range(int(input())):
        d, i, b = map(int, input().split())
        ingredients_prices = list(map(int, input().split()))
        cakes = [list(map(int, input().split())) for _ in range(b)]
        min_cost = 1e10
        for total, *pairs in cakes:
            current_cost = 0
            for i in range(0, 2 * total, 2):
                ingredient_index, ingredient_quantity = pairs[i], pairs[i + 1]
                current_cost += ingredients_prices[ingredient_index] * ingredient_quantity
            if current_cost < min_cost:
                min_cost = current_cost
        print(d // min_cost)
main()
