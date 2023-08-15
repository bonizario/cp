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

# 2019 Regionals

### A. Arte Valiosa (Union-Find)

A Mona Dura é uma das obras de arte mais valiosas do museu da Nlogônia. A famosa pintura fica em exibição num salão retangular de M por N metros. A entrada do salão fica em um canto, e a Mona fica no canto diagonalmente oposto à entrada.

Para impedir roubos, o salão dispõe de sensores de movimento, que são ativados toda noite quando o museu fecha. Cada sensor tem um valor de sensibilidade S, tal que o sensor dispara um alarme se detectar qualquer movimento a no máximo S metros de distância dele.

Um ladrão invadiu o museu esta noite com a intenção de roubar a Mona Dura. Para isso, ele precisa entrar no salão e chegar até a pintura sem ser detectado por nenhum sensor de movimento. Ou seja, ele tem que manter uma distância maior do que S i metros do i-ésimo sensor o tempo todo, para todos os sensores.

O ladrão obteve acesso às plantas do museu, e portanto sabe as dimensões do salão e as coordenadas e sensibilidades de cada um dos sensores. Dadas essas informações, sua tarefa é determinar se o roubo é possı́vel ou não.

**Entrada**

A primeira linha contém três inteiros, M, N e K, as dimensões do salão e o número de sensores de movimento, respectivamente (10 ≤ M, N ≤ 104 , 1 ≤ K ≤ 1000). A entrada do salão fica no ponto (0, 0) e a pintura fica no ponto (M, N).

Cada uma das K linhas seguintes corresponde a um dos K sensores e contém três inteiros, X, Y e S, onde (X, Y) indica a localização do sensor e S indica a sua sensibilidade (0 < X < M, 0 < Y < N, 0 < S ≤ 104). Todas as dimensões e coordenadas da entrada são em metros. É garantido que todos os sensores têm coordenadas distintas.

**Saída**

Seu programa deve produzir uma única linha contendo o caractere ‘S’ caso seja for possı́vel roubar a pintura, ou o caractere ‘N’ caso contrário.

**Exemplos de Entrada**

    10 22 2
    4 6 5
    6 16 5

    10 10 2
    3 7 4
    5 4 4

    100 100 3
    40 50 30
    5 90 50
    90 10 5

**Exemplos de Saída**

    S

    N

    S

```cpp
#include <bits/stdc++.h>
using namespace std;

double calc_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((double)(x1 - x2), 2) + pow((double)(y1 - y2), 2));
}

int find(vector<int>& G, int a) {
    if (a == G[a]) {
        return a;
    }
    return G[a] = find(G, G[a]);
}

void unify(vector<int>& G, vector<int>& S, int a, int b) {
    a = find(G, a), b = find(G, b);
    if (S[a] >= S[b]) {
        G[b] = a;
        S[a] += S[b];
    } else {
        G[a] = b;
        S[b] += S[a];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int m, n, k, x, y, range;
    cin >> m >> n >> k;
    vector<vector<double>> distances(k + 4, vector<double>(k + 4));
    vector<vector<int>> sensors(k, vector<int>(3));
    for (int i = 0; i < k; i++) {
        cin >> x >> y >> range;
        sensors[i][0] = x, sensors[i][1] = y, sensors[i][2] = range;
    }

    for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
            distances[i][j] = calc_distance(sensors[i][0], sensors[i][1], sensors[j][0], sensors[j][1]);
        }
    }
    for (int i = 0; i < k; i++) {
        distances[i][k] = calc_distance(sensors[i][0], sensors[i][1], 0, sensors[i][1]);      // LEFT
        distances[i][k + 1] = calc_distance(sensors[i][0], sensors[i][1], m, sensors[i][1]);  // RIGHT
        distances[i][k + 2] = calc_distance(sensors[i][0], sensors[i][1], sensors[i][0], n);  // TOP
        distances[i][k + 3] = calc_distance(sensors[i][0], sensors[i][1], sensors[i][0], 0);  // BOTTOM
    }

    // DEBUG
    // cout << "DISTANCES\n";
    // for (int i = 0; i < k + 4; i++) {
    //     for (int j = 0; j < k + 4; j++) {
    //         cout << distances[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "END\n";

    vector<int> G(k + 4), S(k + 4);
    for (int i = 0; i < k + 4; i++) {
        G[i] = i, S[i] = 1;
    }

    for (int i = 0; i < k; i++) {
        if (distances[i][k] <= sensors[i][2]) {
            unify(G, S, i, k);
        }
        if (distances[i][k + 1] <= sensors[i][2]) {
            unify(G, S, i, k + 1);
        }
        if (distances[i][k + 2] <= sensors[i][2]) {
            unify(G, S, i, k + 2);
        }
        if (distances[i][k + 3] <= sensors[i][2]) {
            unify(G, S, i, k + 3);
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (distances[i][j] <= (sensors[i][2] + sensors[j][2])) {
                unify(G, S, i, j);
            }
        }
    }

    bool possible = true;
    if (find(G, G[k]) == find(G, G[k + 1]) ||      // LEFT  <-> RIGHT
        find(G, G[k + 2]) == find(G, G[k + 3]) ||  // TOP   <-> BOTTOM
        find(G, G[k]) == find(G, G[k + 3]) ||      // LEFT  <-> BOTTOM
        find(G, G[k + 1]) == find(G, G[k + 2])) {  // RIGHT <-> TOP
        possible = false;
    }

    cout << (possible ? "S\n" : "N\n");

    return 0;
}
```

### D. Delação Premiada (DFS to compute tree ranks from root, DFS from leaves to root to compute unique visited nodes)

#### Current solution uses 2 graphs, optimizations are most likely possible

A máfia nlogoniana tem N membros no total, e cada um é identificado por um inteiro entre 1 e N , onde 1 é o ID do chefão. Além disso, todo membro é subordinado direto de um outro membro, exceto o chefão.

Mesmo após meses de investigação, a polı́cia ainda não tem informação suficiente para prender nenhum membro da máfia por nenhum crime. Por isso, resolveram pedir a ajuda de um vidente: dado um membro da máfia, o vidente pode magicamente adivinhar os crimes que ele cometeu, e a polı́cia pode então confirmá-los através de interrogatório.

Além disso, quando um mafioso nlogoniano é interrogado, ele não só admite os seus crimes, mas também delata os crimes de seu superior direto, em troca de uma pena mais leve. Se este já não tiver sido preso, a polı́cia pode interrogá-lo também, e ele vai então delatar o superior dele, e assim por diante, até chegarem no chefão.

Infelizmente, o vidente só tem energia suficiente para adivinhar os crimes de no máximo K mafiosos, e a polı́cia quer usar seus poderes cuidadosamente pra prender o máximo possı́vel de bandidos. Dado o valor de K e a estrutura completa da máfia, qual a quantidade máxima de mafiosos que a polı́cia consegue prender?

**Entrada**

A primeira linha contém dois inteiros, N e K, onde N é o número de membros da máfia e K é o número máximo de mafiosos cujos crimes o vidente pode adivinhar (3 ≤ N ≤ 10^5 , 1 ≤ K < N). A segunda linha contém N − 1 inteiros, onde o i-ésimo deles identifica o superior direto do mafioso de ID i + 1.

É garantido que todos os inteiros da segunda linha estão entre 1 e N, e que todos os membros da máfia são subordinados do chefão, direta ou indiretamente.

**Saída**

Seu programa deve produzir uma única linha com um inteiro representando o número máximo de mafiosos que a polı́cia pode prender.

**Exemplos de Entrada**

    8 2
    1 1 2 3 4 4 6

    10 3
    1 1 2 2 3 3 4 4 5

**Exemplos de Saída**

    7

    8

```cpp
#include <bits/stdc++.h>
using namespace std;

void dfs_ranks(vector<vector<int>>& inverse_adj, int node, vector<bool>& visited, unordered_map<int, int>& rank) {
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    if (node == 1) {
        rank[node] = 1;
    }
    for (auto u : inverse_adj[node]) {
        rank[u] = rank[node] + 1;
        dfs_ranks(inverse_adj, u, visited, rank);
    }
}

void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited, int& current_seen) {
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    current_seen += 1;
    for (auto u : adj[node]) {
        dfs(adj, u, visited, current_seen);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, k, superior;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> inverse_adj(n + 1);
    unordered_map<int, bool> is_leaf;
    unordered_map<int, int> rank;

    for (int i = 1; i <= n; i++) {
        is_leaf[i] = true;
    }
    rank[1] = 1;
    for (int i = 1; i < n; i++) {
        cin >> superior;
        adj[i + 1].push_back(superior);
        inverse_adj[superior].push_back(i + 1);
        is_leaf[superior] = false;
    }

    vector<bool> visited(n + 1, false);
    dfs_ranks(inverse_adj, 1, visited, rank);

    vector<pair<int, int>> leaves;  // {rank, node_index}
    for (int i = 1; i <= n; i++) {
        if (is_leaf[i]) {
            leaves.push_back({rank[i], i});
        }
        visited[i] = false;
    }

    sort(leaves.begin(), leaves.end(), greater<pair<int, int>>());

    // DEBUG
    // for (int i = 0; i < (int)leaves.size(); i++) {
    //     cout << "rank=" << leaves[i].first << " i=" << leaves[i].second << "\n";
    // }

    vector<pair<int, int>> seen_with_dfs;

    for (auto [r, i] : leaves) {
        int current_seen = 0;
        dfs(adj, i, visited, current_seen);
        seen_with_dfs.push_back({current_seen, i});
    }

    sort(seen_with_dfs.begin(), seen_with_dfs.end(), greater<pair<int, int>>());

    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += seen_with_dfs[i].first;
    }
    cout << ans << "\n";

    return 0;
}
```
