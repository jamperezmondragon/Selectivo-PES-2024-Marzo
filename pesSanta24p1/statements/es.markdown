Moriarty ha puesto en marcha otro de sus sofisticados planes, esta vez monopolizando las carreteras de la ciudad para controlarlo todo, así que Sherlock y Watson deben idear un plan para detenerlo.


La ciudad de Londres está dividida en $N$ zonas que están conectadas a través de $M$ carreteras. Moriarty ha puesto una tarifa a cada una de estas carreteras que hay que pagar para poder moverse libremente por ellas. Las zonas están numeradas del $1$ al $N$. La $i$-ésima carretera conecta las zonas $a_i$ y $b_i$, y tiene un costo de $c_i$.


El duo quiere establecer dos bases de vigilancia en algún par de zonas, y quieren poder llegar a todas las zonas de la ciudad desde al menos alguna de ellas, obviamente gastando la mínima cantidad de dinero posible.


No todas las zonas son igual de idóneas para establecer una base, así que quieren probar $Q$ posibles parejas de bases posibles, tal que Sherlock vigile la base $S_i$ y Watson la base $W_i$. Como Sherlock dice que este problema es trivial, Watson te ha pedido ayuda para disimular. Ayúdalo a calcular el mínimo costo para cada par de zonas.

# Entrada

En la primera línea dos enteros $N$ y $M$, la cantidad de fábricas y la cantidad de carreteras respectivamente.

En las siguientes $M$ líneas, tres enteros $a_i$, $b_i$ y $c_i$, una pareja de zonas y el costo que Moriarty ha establecido para poder transitar la carretera que las conecta.

En la siguiente línea, un entero $Q$, la cantidad de preguntas.

En las siguientes $Q$ líneas, dos enteros $S_i$ y $W_i$.

# Salida

Deberás imprimir $Q$ enteros separados por un salto de línea, la suma mínima del costo de las carreteras para cada pregunta.

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

- $2 \leq N \leq 10^5$
- $1 \leq M \leq 2 \times 10^5$
- $1 \leq a_i, b_i, S_i, W_i\leq N$
- $1 \leq c_i \leq 10^9$
- $1 \leq Q \leq 10^5$
- $a_i \neq b_i$
- $S_i \neq W_i$
- Por cada pareja de vértices, existe a lo más una arista.

# Subtareas

- **Subtarea 1** (17 puntos)
  - $Q = 1$
- **Subtarea 2** (60 puntos)
  - $2 \leq N \leq 4 \times 10^3$
  - $1 \leq Q \leq 4 \times 10^3$
- **Subtarea 3** (23 puntos)
  - Sin consideraciones adicionales.
