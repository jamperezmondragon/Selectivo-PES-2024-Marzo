
¿Por qué el ser, y no la nada?

Heidegger es un filósofo incomprensible. Tanto así, que se inventa palabras nuevas para sonar complicado (dice que es necesario porque las palabras han perdido su significado original). Un profesor organizó las palabras chistosas de heidegger en una lista, cada una representada por un entero positivo. Tu le puedes hacer preguntas, pero como son unos snobs terribles, te dará poca información en cada una.

# Problema

El jurado tiene un arreglo escondido, de enteros positivos distintos. Tu quieres adivinarlo, y para hacer esto, puedes preguntar por todas las diferencias de parejas de valores, para un subconjunto de índices. Además, puedes preguntar por el valor del arreglo en un índice. Quieres minimizar la cantidad de preguntas que haces.

#Implementación

 - Deberás implementar la función `EncuentraArreglo(int N)` y la función `recibeRespuesta(int T, int D[])`.

 - Al inicio de cada caso, el evaluador llama la función `EncuentraArreglo(int N)`. Esto quiere decir que en ese caso de prueba, el tamaño del arreglo escondido es $N$. Digamos que el arreglo escondido es $A$.

 - Para obtener información puedes mandar llamar a la función `diferencias(int M, int S[])`. Le pasas un entero positivo $M$, y un arreglo $S$ con $M$ índices.

 Es decir, para todo $0 \le i \le M - 1$, se debe cumplir que $0 \le S[i] \le N - 1$. Inmediatamente después, el evaluador llamará la función `recibeRespuesta(int T, int D[])`, $T$ siempre será igual a $\frac{M(M - 1)}{2}$, y el arreglo $D$ tendrá $T$ elementos, las diferencias absolutas de cada pareja de valores en el arreglo escondido con índices en $S$.

 O sea, para cada $0 \le i < j \le M - 1$, el valor $\lvert A[S[i]] - A[S[j]] \lvert$ estará en el arreglo $D$. El orden de dichas diferencias siempre es arbitrario.

 - También, tu programa puede mandar llamar la función `valor(int i)`. Esta regresa un entero, en particular, te regresa el valor de $A[i]$. Se debe cumplir que $0 \le i \le N - 1$.

 - Cuando tengas lista tu respuesta, debes llamar la función `respuesta(int K, int R[])`, donde $R$ es el arreglo que afirmas que es la respuesta, y $K$ es su tamaño ($K$ debe ser $N$).




{{libinteractive:download}}

#Evaluación

Tu puntaje dependerá de la cantidad de veces que llames a la función `diferencias` o a la función `valor`. Si la cantidad total de preguntas que hiciste es $Q$, entonces:

- Si $0 \leq Q \leq 30$ obtendrás todos los puntos.
- Si $30 < Q < 60$ obtendrás una cantidad parcial de puntos.
- Si $60 \leq Q$ no obtendrás ningún punto.

También obtendrás $0$ puntos si al mandar llamar la función `diferencias` o `valor`  los argumentos no cumplen con los límites establecidos.

# Límites

- $1 \leq N \leq 250$
- Todos los valores del arreglo escondido son distintos y caben en un entero de 31 bits.

# Subtareas

- **Subtarea 1** (5 puntos)
  - $1 \leq N \leq 30$
- **Subtarea 2** (28 puntos)
  - Los valores del arreglo están ordenados de manera creciente o de manera decreciente
- **Subtarea 3** (45 puntos)
  - $A[0] = 1$
- **Subtarea 4** (22 puntos)
  - Sin consideraciones adicionales.
