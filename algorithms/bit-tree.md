# Binary Indexed Tree (BIT) | Fenwick Tree

Let,  **f**  be some group operation (binary associative function over a set with identity element and inverse elements) and  **A** be an array of integers of length  **N**.

Fenwick tree is a data structure which:

* Calculates the value of function  **f** in the given range **[l,r]** in **O(log N)**.
* Updates the value of an element of  **A** in **O(log N)**.
* Requires **O(N)** memory, or in other words, exactly the same memory required for  **A**.
* Is easy to use and code, especially, in the case of multidimensional arrays.

The most common application of Fenwick tree is calculating the sum of a range (i.e. using addition over the set of integers _Z_): 

_f(A1, A2, A3, ..., Ak) = A1 + A2 + A3 + ... + Ak_

Fenwick tree is also called Binary Indexed Tree, or just BIT abbreviated.

# Beecrowd

### 1088. Bolhas e Baldes

Andrea, Carlos e Marcelo são muito amigos e passam todos os finais de semana à beira da piscina. Enquanto Andrea se bronzeia ao sol, os dois ficam jogando Bolhas. Andrea, uma cientista da computação muito esperta, já disse a eles que não entende por que passam tanto tempo jogando um jogo tão primário.

Usando o computador portátil dela, os dois geram um inteiro aleatório N e uma seqüência de inteiros, também aleatória, que é uma permutação de 1, 2, ... ,N.

O jogo então começa, cada jogador faz um movimento, e a jogada passa para o outro jogador. Marcelo é sempre o primeiro a começar a jogar. Um movimento de um jogador consiste na escolha de um par de elementos consecutivos da seqüência que estejam fora de ordem e em inverter a ordem dos dois elementos. Por exemplo, dada a seqüência 1, 5, 3, 4, 2, o jogador pode inverter as posições de 5 e 3 ou de 4 e 2, mas não pode inverter as posições de 3 e 4, nem de 5 e 2. Continuando com o exemplo, se o jogador decide inverter as posições de 5 e 3 então a nova seqüência será 1, 3, 5, 4, 2.

Mais cedo ou mais tarde, a seqüência ficará ordenada. Perde o jogador impossibilitado de fazer um movimento. Andrea, com algum desdém, sempre diz que seria mais simples jogar cara ou coroa, com o mesmo efeito. Sua missão, caso decida aceitá-la, é determinar quem ganha o jogo, dada a seqüência inicial.

**Entrada**

A entrada contém vários casos de teste. Os dados de cada caso de teste estão numa única linha, e são inteiros separados por um espaço em branco. Cada linha contém um inteiroN (2 ≤ N ≤ 10^5), seguido da seqüência inicial P = (X1, X2, ...,XN) de N inteiros distintos dois a dois, onde1 ≤ Xi ≤ N para 1 ≤ i ≤ N.

O final da entrada é indicado por uma linha que contém apenas o número zero.

**Saída**

Para cada caso de teste da entrada seu programa deve imprimir uma única linha, com o nome do vencedor, igual a Carlos ou Marcelo., sem espaços em branco.

**Exemplo de Entrada**

    5 1 5 3 4 2
    5 5 1 3 4 2
    5 1 2 3 4 5
    6 3 5 2 1 4 6
    5 5 4 3 2 1
    6 6 5 4 3 2 1
    0

**Exemplo de Saída**

    Marcelo
    Carlos
    Carlos
    Carlos
    Carlos
    Marcelo

```cpp
#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &bit, int n, int idx, int val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int getSum(vector<int> &bit, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void convert(vector<int> &arr, int n) {
    // convert {7, -90, 100, 1} to {3, 1, 4, 2}
    vector<int> temp(arr);
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
    }
}

int countSwaps(vector<int> &arr, int n) {
    int swaps = 0;
    convert(arr, n);
    vector<int> bit(n + 1);
    fill(bit.begin(), bit.end(), 0);
    for (int i = n - 1; i >= 0; i--) {
        // get count of elements smaller than arr[i]
        swaps += getSum(bit, arr[i] - 1);
        // add current element to BIT
        update(bit, n, arr[i], 1);
    }
    return swaps;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n && n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (countSwaps(arr, n) & 1) {
            cout << "Marcelo\n";
        } else {
            cout << "Carlos\n";
        }
    }
    return 0;
}

// {3, 1, 4, _2}
// [0, 0, 0, 0]  BEFORE
// swaps += 0
// [0, 1, 1, 1]  AFTER current = 2, increment 2 3 4

// {3, 1, _4, 2}
// [0, 1, 1, 1]  BEFORE
// swaps += 1
// [0, 1, 1, 2]  AFTER current = 4, increment 4

// {3, _1, 4, 2}
// [0, 1, 1, 2]  BEFORE
// swaps += 0
// [1, 2, 2, 3]  AFTER current = 1, increment 1 2 3 4

// {_3, 1, 4, 2}
// [1, 2, 2, 3]  BEFORE
// swaps += 2
// [1, 2, 3, 4]  AFTER current = 3, increment 3 4

// {3, 1, 4, 2}
// {1, 3, 4, 2}
// {1, 3, 2, 4}
// {1, 2, 3, 4}
```

### 2539. High Five

A seleção Nlogonense de Basquetebol está na grande final da Copa do Mundo de Basquete, e o jogo está prestes a começar! Neste momento, os N atletas da seleção se preparam para entrar em quadra.

Os atletas são numerados de 1 a N. Inicialmente, os atletas estão em uma fila na beira do campo. Os atletas entram no campo um por um, na ordem de seus números. Assim, o atleta 1 é o primeiro a sair da fila e entrar na quadra. Em seguida, o atleta 2 sai da fila e entra na quadra, e assim por diante.

Ao sair da fila, cada atleta cumprimenta todos os atletas que estão em sua frente na fila com um high five. Por exemplo, considere que N=4 e inicialmente a fila é 3 1 2 4, onde o atleta 4 é o mais próximo da quadra. O atleta 1, ao ir para a quadra, faz um high five com os atletas 2 e 4. O atleta 2, por sua vez, faz um high five apenas com o atleta 4 ao sair da fila. O atleta 3 também faz um high five apenas com o atleta 4 (note que os atletas 1 e 2 já saíram da fila). Por fim, o último atleta não cumprimenta ninguém.

Sua tarefa é determinar o número total de high fives que serão feitos.

**Entrada**

A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém o inteiro N (1 ≤ N ≤ 10^5). A segunda linha contém N inteiros, indicando a ordem em que os atletas estão inicialmente na fila. O último inteiro presente na linha indica o atleta mais próximo da quadra.

A entrada termina com fim-de-arquivo (EOF).

**Saída**

Para cada caso de teste, imprima uma linha contendo o número total de high fives que serão feitos.

**Exemplo de Entrada**

    4
    3 1 2 4
    5
    5 4 3 2 1
    5
    1 2 3 4 5

**Exemplo de Saída**

    4
    0
    10

```cpp
// Adaptation of 1088
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1e5;

void update(vector<ll>& bit, ll n, ll idx, ll val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

ll getSum(vector<ll>& bit, ll idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

ll countSwaps(vector<ll>& arr, vector<ll>& bit, ll n) {
    ll swaps = 0;
    fill(bit.begin(), bit.begin() + n + 1, 0);
    for (ll i = n - 1; i >= 0; i--) {
        swaps += getSum(bit, arr[i] - 1);
        update(bit, n, arr[i], 1);
    }
    return swaps;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, sn;
    vector<ll> arr(MAX_N), bit(MAX_N + 1);
    while (cin >> n) {
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sn = n * (n - 1) / 2;
        cout << sn - countSwaps(arr, bit, n) << "\n";
    }

    return 0;
}
```
