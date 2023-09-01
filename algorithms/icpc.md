# ICPC

# 2006 Regionals

### C. Países em Guerra (Dijkstra)

Cada cidade possui uma agência postal onde as cartas são enviadas. As cartas podem ser enviadas diretamente ao seu destino ou a outras agências postais, até que a carta chegue à agência postal da cidade de destino, se isso for possível.

Uma agência postal na cidade A pode enviar diretamente uma carta impressa para a agência postal da cidade B se houver um acordo de envio de cartas, que determina o tempo, em horas, que uma carta leva para chegar da cidade A à cidade B (e não necessariamente o contrário). Se não houver um acordo entre as agências A e B, a agência A pode tentar enviar a carta a quantas agências for necessário para que a carta chegue ao seu destino, se isso for possível.

Algumas agências são interligadas por meios eletrônicos de comunicação, como satélites e fibras ópticas. Antes da guerra, essas ligações atingiam todas as agências, fazendo com que uma carta fosse enviada de forma instantânea, mas durante o período de hostilidades cada país passou a controlar a comunicação eletrônica e uma agência somente pode enviar uma carta a outra agência por meio eletrônico (ou seja, instantaneamente) se ela estiver no mesmo país. Duas agências, A e B, estão no mesmo país se houver uma forma de uma carta impressa enviada de uma das agências ser entregue na outra agência.

O serviço de espionagem do seu país conseguiu obter o conteúdo de todos os acordos de envios de mensagens existentes no mundo e deseja descobrir o tempo mínimo para se enviar uma carta entre diversos pares de cidades. Você seria capaz de ajudá-lo?

**Entrada**

A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém dois inteiros separados por um espaço, N (1 ≤ N ≤ 500) e E (0 ≤ E ≤ N^2), indicando o número de cidades (numeradas de 1 a N) e de acordos de envio de mensagens, respectivamente. Seguem-se, então, E linhas, cada uma com três inteiros separados por espaços, X, Y e H (1 ≤ X, Y ≤ N, 1 ≤ H ≤ 1000), indicando que existe um acordo para enviar uma carta impressa da cidade X à cidade Y , e que tal carta será entregue em H horas.

Em seguida, haverá uma linha com um inteiro K (0 ≤ K ≤ 100), o número de consultas. Finalmente, virão K linhas, cada uma representando uma consulta e contendo dois inteiros separados por um espaço, O e D (1 ≤ O, D ≤ N). Você deve determinar o tempo mínimo para se enviar uma carta da cidade O à cidade D. A entrada termina quando N = E = 0.

**Saída**

Para cada caso de teste da entrada seu programa deve produzir K linhas na saída. A I-ésima linha deve conter um inteiro M , o tempo mínimo, em horas, para se enviar uma carta na I-ésima consulta. Se não houver meio de comunicação entre as cidades da consulta, você deve imprimir ”Nao e possivel entregar a carta”(sem acentos).

Imprima uma linha em branco após cada caso de teste.

**Exemplo de Entrada**

    4 5
    1 2 5
    2 1 10
    3 4 8
    4 3 7
    2 3 6
    5
    1 2
    1 3
    1 4
    4 3
    4 1
    3 3
    1 2 10
    2 3 1
    3 2 1
    3
    1 3
    3 1
    3 2
    0 0

**Exemplo de Saída**

    0
    6
    6
    0
    Nao e possivel entregar a carta

    10
    Nao e possivel entregar a carta
    0

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int POSITIVE_INFINITY = 1e9;
const int MAXN = 501;
vector<pii> adj[MAXN];
bool visited[MAXN];
bool direct_path[MAXN][MAXN];
int dist[MAXN];

void dijkstra(int n, int s) {
    for (int i = 1; i <= n; i++)
        dist[i] = POSITIVE_INFINITY, visited[i] = false;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(dist[s], s));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto &[w, v] : adj[u]) {
            if (direct_path[u][v] && direct_path[v][u]) {
                dist[v] = min(dist[u], dist[v]);
                pq.push(pii(dist[v], v));
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, e, x, y, h, k;
    while (true) {
        cin >> n >> e;
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            for (int j = 1; j <= n; j++)
                direct_path[i][j] = false;
        }
        for (int i = 0; i < e; i++) {
            cin >> x >> y >> h;
            direct_path[x][y] = true;
            adj[x].push_back(make_pair(h, y));
        }
        cin >> k;
        while (k--) {
            cin >> x >> y;
            dijkstra(n, x);
            if (dist[y] < POSITIVE_INFINITY) {
                cout << dist[y] << "\n";
            } else {
                cout << "Nao e possivel entregar a carta\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
```

# 2008 Regionals

### F. Loop Musical (Count peaks in array)

Fernandinha é uma amiga muito querida e pediu sua ajuda para determinar quantos picos existem no seu loop musical.

**Entrada**

A entrada contém vários casos de teste. A primeira linha de um caso de teste contém um inteiro N, representando o número de amostras no loop musical de Fernandinha (2 ≤ N ≤ 10^4). A segunda linha contém N inteiros Hi, separados por espaços, representando a sequência de magnitudes das amostras(-10^4 ≤ Hi ≤ 10^4 para 1 ≤ i ≤ N, H1 ≠ HN e Hi ≠ Hi+1 para 1 ≤ i < N). Note que H1 segue HN quando o loop é reproduzido.

O final da entrada é indicado por uma linha que contém apenas o número zero.

**Saída**

Para cada caso de teste da entrada seu programa deve imprimir uma única linha, contendo apenas um inteiro, o número de picos existentes no loop musical de Fernandinha.

**Exemplo de Entrada**

    2
    1 -3
    6
    40 0 -41 0 41 42
    4
    300 450 449 450
    0

**Exemplo de Saída**

    2
    2
    4

```py
def main():
    while True:
        n = int(input())
        if n == 0:
            break
        h = list(map(int, input().split()))
        h.extend(h[:2])
        peaks = 0
        for i in range(1, n + 1):
            if (h[i] - h[i - 1]) * (h[i + 1] - h[i]) < 0:
                peaks += 1
        print(peaks)
main()
```

### J. Vampiros (Unfair coin flipping)

Tais batalhas são realizadas com base nas características de cada personagem envolvido e com a ajuda de um dado comum de seis faces. Por simplicidade, vamos considerar apenas as lutas entre dois vampiros, vampiro 1 e vampiro 2. Cada um possui uma energia vital (chamaremos de EV1 e EV2 respectivamente) e, além disso, são determinadas uma força de ataque AT e uma capacidade de dano D.

O combate é realizado em turnos da maneira descrita a seguir. A cada turno um dado é rolado, se o valor obtido for menor do que ou igual a AT, o vampiro 1 venceu o turno, caso contrário o vampiro 2 é quem venceu. O vencedor suga energia vital do adversário igual ao valor D, ou seja, D pontos de EV são diminuídos do perdedor e acrescentados ao vencedor. O combate segue até que um dos vampiros fique com EV igual a ou menor do que zero.

Por exemplo, suponhamos que EV1=7, EV2=5, AT=2 and D=4. Rola-se o dado e o valor obtido foi 3. Nesse caso, o vampiro 2 venceu o turno e, portanto, 4 pontos de EV são diminuídos do vampiro 1 (EV1) e acrescentados ao vampiro 2 (EV2) Sendo assim, os novos valores seriam EV1=3 e EV2=9. Observe que se no próximo turno o vampiro 2 ganhar novamente, o combate irá terminar. Os valores de AT e D são constantes durante todo o combate, apenas EV1 e EV2 variam.

Apesar de gostar muito do jogo, Felipinho acha que os combates estão muito demorados e gostaria de conhecer de antemão a probabilidade de vencer, para saber se vale a pena lutar. Assim, ele pediu que você escrevesse um programa que, dados os valores iniciais de EV1, EV2, além de AT e D, calculasse a probabilidade de o vampiro 1 vencer o combate.

**Entrada**

A entrada consiste de vários casos de teste. Cada caso de teste consiste de uma única linha, contendo 4 inteiros EV1, EV2, AT e D separados por espaços (1 ≤ EV1, EV2 ≤ 10, 1 ≤ AT ≤ 5 and 1 ≤ D ≤ 10). O final da entrada é indicado por uma linha contendo quatro zeros, separados por espaços.

**Saída**

Para cada caso de teste da entrada seu programa deve imprimir uma única linha. A linha deve conter apenas um número real, escrito com precisão de uma casa decimal, representando, em termos de percentagem, a probabilidade de o vampiro 1 vencer o combate.

**Exemplo de Entrada**

    1 1 3 1
    1 2 1 1
    8 5 3 1
    7 5 2 4
    0 0 0 0

**Exemplo de Saída**

    50.0
    3.2
    61.5
    20.0

```py
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
```

# 2010 Regionals

### D. Desvio de Rota (Dijkstra)

O sistema rodoviário de um país interliga todas as suas N cidades de modo que, a partir de uma cidade qualquer, é possível chegar a cada uma das outras cidades trafegando pelas estradas existentes. Cada estrada liga duas cidades distintas, tem mão dupla e um único posto de pedágio (o pedágio é pago nos dois sentidos de tráfego). As estradas não se intersectam a não ser nas cidades. Nenhum par de cidades é interligado por duas ou mais estradas.

{...} Cada encomenda deve ser levada de uma cidade A para uma outra cidade B. A direção da Transportadora Dias define, para cada encomenda, uma rota de serviço, composta por C cidades e C−1 estradas: a primeira cidade da rota de serviço é a origem da encomenda, a última o destino da encomenda. A rota de serviço não passa duas vezes pela mesma cidade, e o veículo escolhido para fazer o transporte de uma encomenda pode trafegar apenas pela rota de serviço definida.

Certo dia, no entanto, o veículo que executava uma entrega quebrou e precisou ser levado para conserto em uma cidade que não está entre as cidades de sua rota de serviço. A direção da Transportadora Dias quer saber qual é o menor custo total, em termos de pedágio, para que o veículo entregue a encomenda na cidade destino, a partir da cidade em que foi consertado, mas com uma restrição adicional: se em algum momento o veículo passar por uma das cidades que compõem a sua rota de serviço, ele deve voltar a obedecer a rota de serviço.

**Entrada**

A entrada contém vários casos de teste. A primeira linha de um caso de teste contém quatro inteiros N, M, C e K (4 ≤ N ≤ 250, 3 ≤ M ≤ N×(N−1)/2, 2 ≤ C ≤ N−1 e C ≤ K ≤ N−1), representando, respectivamente, o número de cidades do país, o número de estradas, o número de cidades na rota de serviço e a cidade em que o veículo foi consertado. As cidades são identificadas por inteiros de 0 a N−1. A rota de serviço é 0, 1, ... , C−1, ou seja, a origem é 0, de 0 passa para 1, de 1 para 2 e assim por diante, até o destino C−1.

As M linhas seguintes descrevem o sistema rodoviário do país. Cada uma dessas linhas descreve uma estrada e contém três inteiros U, V e P (0 ≤ U, V ≤ N−1, U ≠ V, 0 ≤ P ≤ 250), indicando que há uma estrada interligando as cidades U e V com custo de pedágio P. O último caso de teste é seguido por uma linha contendo quatro zeros separados por espaço em branco.

**Saída**

Para cada caso de teste, o seu programa deve imprimir uma única linha, contendo um único inteiro T, o custo total mínimo necessário, em termos de pedágio, para que o veículo chegue ao destino.

**Exemplo de Entrada**

    4 6 3 3
    0 1 10
    1 2 10
    0 2 1
    3 0 1
    3 1 10
    3 2 10
    6 7 2 5
    5 2 1
    2 1 10
    1 0 1
    3 0 2
    3 4 2
    3 5 3
    5 4 2
    5 5 2 4
    0 1 1
    1 2 2
    2 3 3
    3 4 4
    4 0 5
    0 0 0 0

**Exemplo de Saída**

    10
    6
    6

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 250;
const int POSITIVE_INFINITY = 1e9;

int dist[MAXN];
int route[MAXN];
bool visited[MAXN];
vector<pii> adj[MAXN];

void dijkstra(int n, int c, int s) {
    for (int i = 0; i < n; i++)
        dist[i] = POSITIVE_INFINITY, visited[i] = false;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, s));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto &[w, v] : adj[u]) {
            if (u >= c - 1 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v], v));
            }
        }
        if (u < c - 1 && dist[c - 1] > dist[u] + route[c - 1] - route[u]) {
            dist[c - 1] = dist[u] + route[c - 1] - route[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m, c, k, u, v, p;
    while (true) {
        cin >> n >> m >> c >> k;
        if (n == 0 && m == 0 && c == 0 && k == 0) break;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> p;
            adj[u].push_back(pii(p, v));
            adj[v].push_back(pii(p, u));
            if (abs(u - v) == 1)
                route[max(u, v)] = p;
        }
        for (int i = 1; i <= c - 1; i++) {
            route[i] += route[i - 1];
        }
        dijkstra(n, c, k);
        cout << dist[c - 1] << "\n";
    }
    return 0;
}
```

### I. Ir e Vir (Kosaraju's Algorithm for Strongly Connected Components (SCC))

Numa certa cidade há N intersecções ligadas por ruas de mão única e ruas com mão dupla de direcão. Evidentemente é necessário que se possa viajar entre quaisquer duas intersecções, isto é, dadas duas intersecções V e W, deve ser possível viajar de V para W e de W para V.

Sua tarefa é escrever um programa que leia a descrição do sistema de tráfego de uma cidade e determine se o requisito de conexidade é satisfeito ou não.

**Entrada**

A entrada contém vários casos de teste. A primeira linha de um caso de teste contém dois números inteiros N e M, separados por um espaço em branco, indicando respectivamente o número de intersecções (2 ≤ N ≤ 2000) e o número de ruas (2 ≤ M ≤ N(N−1)/2). O caso de teste tem ainda mais M linhas, que contêm, cada uma, uma descrição de cada uma das M ruas. A descrição consiste de três inteiros V, W e P, separados por um espaço em branco, onde V e W são identificadores distintos de intersecções (1 ≤ V, W ≤ N , V ≠ W ) e P pode ser 1 ou 2; se P = 1 então a rua é de mão única, e vai de V para W; se P = 2 então a rua é de mão dupla, liga V e W. Não existe duas ruas ligando as mesmas intersecções.

O último caso de teste é seguido por uma linha que contém apenas dois números zero separados por um espaço em branco.

**Saída**

Para cada caso de teste seu programa deve imprimir uma linha contendo um inteiro G, onde G é igual a 1 se o requisito de conexidade está satisfeito, ou G é igual a 0, caso contrário.

**Exemplo de Entrada**

    4 5
    1 2 1
    1 3 2
    2 4 1
    3 4 1
    4 1 2
    3 2
    1 2 2
    1 3 2
    3 2
    1 2 2
    1 3 1
    4 2
    1 2 2
    3 4 2
    0 0

**Exemplo de Saída**

    1
    1
    0
    0

```py
def main():
    def dfs(v, adj, visited):
        visited[v] = True
        for u in adj[v]:
            if not visited[u]:
                dfs(u, adj, visited)

    # def transpose(n, adj):
    #     transpose_adj = [[] for _ in range(n)]
    #     for i in range(n):
    #         for v in adj[i]:
    #             transpose_adj[v].append(i)
    #     return transpose_adj

    def is_strongly_connected(n, adj, transpose_adj, visited):
        dfs(0, adj, visited)
        if not all(visited):
            return False
        visited = [False] * n
        dfs(0, transpose_adj, visited)
        if not all(visited):
            return False
        return True

    while True:
        n, m = map(int, input().split())
        if n == m == 0:
            break
        visited = [False] * n
        adj = [[] for _ in range(n)]
        transpose_adj = [[] for _ in range(n)]
        for _ in range(m):
            v, w, p = map(int, input().split())
            v, w = v - 1, w - 1
            adj[v].append(w)
            transpose_adj[w].append(v)
            if p == 2:
                adj[w].append(v)
                transpose_adj[v].append(w)
        print(1 if is_strongly_connected(n, adj, transpose_adj, visited) else 0)

main()
```

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
