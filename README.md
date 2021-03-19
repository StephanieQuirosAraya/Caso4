# Caso4

En el presente algoritmo para lograr generar el patrón requerido se partió de que los puntos de una circunferencia se pueden encontrar con las fórmulas x = radio * sin(angulo), y = radio * cos(angulo), esto se usa para generar las circunferencias, el radio de ellas depende del ancho y el largo, para lograr las circunferencias incompletas se divide el alto entre cuatro y se colocan los puntos de la circunferencia en el cuadrante correspondiente.

La n del algoritmo es ancho ya que me da la cantidad de iteraciones que hace el algoritmo.

Al hacer un análisis en general del algoritmo se llega a que f(n) = 53(n*radianes) y la O(n).