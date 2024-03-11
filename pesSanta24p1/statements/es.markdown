Takahashi found an undirected connected graph with $N$ vertices and $M$ edges. The vertices are numbered $1$ through $N$. The $i$-th edge connects vertices $a_i$ and $b_i$, and has a weight of $c_i$.

He will play $Q$ rounds of a game using this graph. In the $i$-th round, two vertices $S_i$ and $T_i$ are specified, and he will choose a subset of the edges such that any vertex can be reached from at least one of the vertices $S_i$ or $T_i$ by traversing chosen edges.

For each round, find the minimum possible total weight of the edges chosen by Takahashi.

# Entrada

En la primera línea dos enteros $N$ y $M$, la cantidad de vertices y la cantidad de aristas respectivamente.

En las siguientes $M$ lineas, tres enteros $a_i$, $b_i$ y $c_i$, la pareja de vertices y el peso de la arista que los conecta.

En la siguiente linea, un entero $Q$, la cantidad de preguntas.

En las siguientes $Q$ lineas, dos enteros $S_i$ y $T_i$.

# Salida

Deberás imprimir $Q$ enteros separados por un salto de linea, la suma minima de las aristas para cada pregunta.

# Ejemplo

||input
4 3
1 2 3
2 3 4
3 4 5
2
2 3
1 4
||output
8
7

||input
1 3
0 3
||output
0

||input
4 6
1 3 5
4 1 10
2 4 6
3 2 2
3 4 5
2 1 3
1
2 3
||output
8

||end

# Límites

- $1 \leq N \leq 10^5$
- $1 \leq M \leq 4 \times 10^5$
- $1 \leq a_i, b_i, S_i, T_i\leq N$
- $1 \leq c_i \leq 10^9$
- $1 \leq Q \leq 10^5$
- $a_i \neq b_i$
- $S_i \neq T_i$

# Subtareas

- **Subtarea 1** (x puntos)
  - $1 \leq N, Q \leq 4 \times 10^3$
- **Subtarea 2** (x puntos)
  - $Q = 1$
- **Subtarea 3** (x puntos)
  - Sin consideraciones adicionales.
