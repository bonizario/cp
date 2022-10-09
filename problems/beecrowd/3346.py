f1, f2 = map(float, input().split())
pib_growth = (1 + f1/100) * (1 + f2/100) - 1
print(f'{(pib_growth*100):.6f}')
