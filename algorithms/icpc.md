# ICPC

# 2011 Regionals

### E. Estacionamento (Ad-Hoc, Linked List, Map)

Um estacionamento utiliza um terreno em que os veículos têm que ser guardados em fila única, um atrás do outro. A tarifa tem o valor fixo de R$ 10,00 por veiculo estacionado, cobrada na entrada, independente de seu porte e tempo de permanência. Como o estacionamento é muito concorrido, nem todos os veículos que chegam ao estacionamento conseguem lugar para estacionar.

Quando um veículo chega ao estacionamento, o atendente primeiro determina se há vaga para esse veículo. Para isso, ele percorre a pé o estacionamento, do início ao fim, procurando um espaço que esteja vago e tenha comprimento maior ou igual ao comprimento do veículo. Para economizar seu tempo e energia, o atendente escolhe o primeiro espaço adequado que encontrar; isto é, o espaço mais próximo do início.

Uma vez encontrada a vaga para o veículo, o atendente volta para a entrada do estacionamento, pega o veículo e o estaciona no começo do espaço encontrado. Se o atendente não encontrar um espaço adequado, o veículo não entra no estacionamento e a tarifa não é cobrada. Depois de estacionado, o veículo não é movido até o momento em que sai do estacionamento.

O dono do estacionamento está preocupado em saber se os atendentes têm cobrado corretamente a tarifa dos veículos estacionados e pediu para você escrever um programa que, dada a lista de chegadas e saídas de veículos no estacionamento, determina o faturamento total esperado.

**Entrada**

A entrada é composta por diversos casos de teste. A primeira linha de um caso de teste contém dois números inteiros C (1 ≤ C ≤ 1000) e N (1 ≤ N ≤ 10000) que indicam respectivamente o comprimento em metros do estacionamento e o número total de eventos ocorridos (chegadas e saídas de veículos). Cada uma das N linhas seguintes descreve uma chegada ou saída. Para uma chegada de veículo, a linha contém a letra 'C', seguida de dois inteiros P (1000 ≤ P ≤ 9999) e Q (1 ≤ Q ≤ 1000), todos separados por um espaço em branco. P indica a placa do veículo e Q o seu comprimento. Para uma saída de veículo, a linha contém a letra 'S' seguida de um inteiro P , separados por um espaço em branco, onde P indica a placa do veículo. As ações são dadas na ordem cronológica, ou seja, na ordem em que acontecem.

No início de cada caso de teste o estacionamento está vazio. No arquivo de entrada, um veículo sai do estacionamento somente se está realmente estacionado, e a placa de um veículo que chega ao estacionamento nunca é igual a placa de um veículo já estacionado.

**Saída**

Para cada caso de teste seu programa deve imprimir uma linha contendo um número inteiro representando o faturamento do estacionamento, em reais.

**Exemplo de Entrada**

    10 7
    C 1234 5
    C 1111 4
    C 2222 4
    C 4321 3
    S 1111
    C 2002 6
    C 4321 3
    30 10
    C 1000 10
    C 1001 10
    C 1002 10
    S 1000
    S 1002
    C 1003 20
    S 1001
    C 1004 20
    S 1004
    C 1005 30
    20 10
    C 1234 20
    C 5678 1
    S 1234
    C 1234 20
    C 5678 1
    S 1234
    C 5678 1
    C 1234 20
    C 5555 1
    S 5678

**Exemplo de Saída**

    30
    50
    40

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    char query;
    int c, n, parked, car_id, car_size, current_end, next_start;
    unordered_map<int, list<pair<int, int>>::iterator> position;
    list<pair<int, int>> parking_lot;

    while (cin >> c >> n) {
        parked = 0;
        position.clear(), parking_lot.clear();
        parking_lot.push_back({0, 0}), parking_lot.push_back({c, c});

        while (n--) {
            cin >> query >> car_id;

            if (query == 'S') {
                parking_lot.erase(position[car_id]);
                continue;
            }

            cin >> car_size;

            // similar to (for int i = 0; i < parking_lot.size() - 1; i++)
            for (auto it = parking_lot.begin(); it != prev(parking_lot.end()); it++) {
                next_start = (*next(it)).first, current_end = (*it).second;
                // if the car fits between current and next intervals
                if (next_start - current_end >= car_size) {
                    // insert the interval before the next interval
                    list<pair<int, int>>::iterator new_position =
                        parking_lot.insert(next(it), {current_end, current_end + car_size});
                    position[car_id] = new_position;
                    parked += 10;
                    break;
                }
            }
        }

        cout << parked << "\n";
    }

    return 0;
}
```

### F. Foco (Ad-Hoc, Pairs, Sort Pairs)

Daniel esta fazendo um curso de Visão Computacional e decidiu reproduzir um trabalho muito interessante visto em aula: ele tirou varias fotos de uma mesma cena, variando apenas o foco, para depois combiná-las em uma unica imagem onde todos os objetos da cena estão nítidos simultaneamente. Para tal, ele precisa que cada objeto apareca nítido em ao menos uma foto.

Daniel sabe que, para cada objeto, existe um intervalo fechado de planos de foco no qual aquele objeto está contido. Por exemplo, na figura abaixo, (i), (ii) e (iii) são três fotos da mesma cena, cada uma tirada com um foco diferente; (iv) é a imagem combinada gerada por Daniel.

Como o cartão de memoria de sua câmera é pequeno, ele pediu sua ajuda para, dados os intervalos de foco de todos os objetos da cena que pretende fotografar, determinar o numero mínimo de fotos que ele deve tirar para que seja possível deixar cada objeto nítido em pelo menos uma foto.

**Entrada**

A entrada é composta por diversos casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 10^6 ) indicando o número de objetos na cena. Cada uma das N linhas seguintes contém dois inteiros A e B (1 ≤ A ≤ B ≤ 10^9) indicando os extremos do intervalo de foco de cada objeto.

**Saída**

Para cada caso de teste, imprima uma linha contendo um inteiro indicando o menor número de fotos que Daniel deve tirar.

**Exemplo de Entrada**

    3
    1 3
    2 5
    4 6
    5
    1 2
    5 6
    3 4
    5 6
    1 2

**Exemplo de Saída**

    2
    3

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, a, b, current, ans;
    vector<pair<int, int>> objects(MAX_N);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            objects[i] = {a, b};
        }

        sort(objects.begin(), objects.begin() + n,
             [](const pair<int, int>& p, const pair<int, int>& q) { return p.second < q.second; });

        current = ans = 0;

        for (int i = 0; i < n; i++) {
            if (objects[i].first > current) {
                ans += 1, current = objects[i].second;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
```

# 2016 Regionals

### D. Divisores (Matemática)

Pense um número positivo n. Agora me diga um divisor A de n. Agora me dê um outro número B que não seja divisor de n. Agora um múltiplo C. E um não múltiplo D. O número que você pensou é...

Parece um truque de mágica, mas é matemática! Será que, conhecendo os números A, B, C e D, você consegue descobrir qual era o número original n? Note que pode existir mais de uma solução!

Neste problema, dados os valores de A, B, C e D, você deve escrever um programa que determine qual o menor número n que pode ter sido pensado ou concluir que não existe um valor possível.

**Entrada**

A entrada consiste de uma única linha que contém quatro números inteiros A, B, C, e D, como descrito acima (1 ≤ A, B, C, D ≤ 109).

**Saída**

Seu programa deve produzir uma única linha. Caso exista pelo menos um número n para os quais A, B, C e D façam sentido, a linha deve conter o menor n possível. Caso contrário, a linha deve conter -1.

**Exemplos de Entrada**

    2 12 8 2

    3 4 60 105

**Exemplos de Saída**

    4

    6

```py
def main():
    # As C is a multiple of N, it is enough to look among the divisors of C
    # for the smallest number that satisfies all restrictions.
    # To do this you test only up to the root of N, so the solution has complexity O(sqrt(C)).

    def is_valid(a, b, c, d, n):
        return (n % a == 0) and (n % b != 0) and (c % n == 0) and (d % n != 0)

    a, b, c, d = map(int, input().split())

    i, ans = 1, c + 1
    while i * i <= c:
        if c % i == 0:                       # "c" is a multiple of "i", so "i" might be "n"
            if is_valid(a, b, c, d, i):      # "i" is a divisor of c
                ans = min(ans, i)
            if is_valid(a, b, c, d, c // i): # "c/i" is also a divisor of c
                ans = min(ans, c // i)
        i += 1

    print(ans if ans < c + 1 else -1)

main()
```
