En épocas recientes, el polo norte se ha visto afectado por el efecto invernadero y las insoportables temperaturas, por esto, el hielo que fungía como carreteras entre las fábricas de Santa Claus se ha debilitado. Santa y Rodolfo se han puesto manos a la obra para mantener a flote su gran empresa mundial.

A Santa le interesa conectar las $N$ fábricas y para ello dispone de $M$ carreteras posibles, dichas carreteras pueden ser construidas por un costo $c_i$, por lo que les interesa minimizar el costo total de construcción. Las fábricas están numeradas del $1$ al $N$. La $i$-ésima carretera conecta las fábricas $a_i$ y $b_i$, y tiene un costo de construcción de $c_i$.

El equipo de Santa quiere probar $Q$ parejas de fábricas posibles, tal que Santa supervisará la fábrica $S_i$ y Rodolfo la fábrica $R_i$, cada otra fábrica debe poder llegar a alguna de estas 2 a través de una serie de carreteras, debido a que nadie del equipo de Santa sabe programar, te han pedido ayuda para determinar el costo mínimo de construir el nuevo sistema de carreteras.

# Entrada

En la primera línea dos enteros $N$ y $M$, la cantidad de fábricas y la cantidad de carreteras respectivamente.

En las siguientes $M$ líneas, tres enteros $a_i$, $b_i$ y $c_i$, una pareja de fábricas y el costo de construir la carretera que las conecta.

En la siguiente línea, un entero $Q$, la cantidad de preguntas.

En las siguientes $Q$ líneas, dos enteros $S_i$ y $R_i$.

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
- $1 \leq a_i, b_i, S_i, R_i\leq N$
- $1 \leq c_i \leq 10^9$
- $1 \leq Q \leq 10^5$
- $a_i \neq b_i$
- $S_i \neq R_i$
- Por cada pareja de vértices, existe a lo más una arista.

# Subtareas

- **Subtarea 1** (20 puntos)
  - $Q = 1$
- **Subtarea 2** (30 puntos)
  - $2 \leq N \leq 4 \times 10^3$
  - $1 \leq Q \leq 4 \times 10^3$
- **Subtarea 3** (50 puntos)
  - Sin consideraciones adicionales.
