# Requisitos del videojuego

A continuación, se mostrarán todos los requisitos necesarios para el desarrollo del videojuego.

## Misión
* Responder la máxima cantidad de preguntas de cultura general establecidas por elequipo de desarrollo que permitan el objetivo definido.
* Ejemplos de preguntas de cultura general:
* ¿Cuántos departamentos tiene el Perú?
* ¿Cuántos países conforman la unión europea?
* ¿Cuál es la longitud de un numero RUC?

## Consola
* El videojuego debe desarrollarse en consola CLR (pantalla negra).
* El equipo de trabajo debe elegir un contexto como sector de salud pública, seguridad,bienestar, factores globales, culturales, sociales, 
ambientales y económicos (es obligatorio elegir uno).
* El videojuego debe ser entendible, claro y amigable para el usuario. Es decir, el equipo detrabajo debe definir los elementos caracteres, 
símbolos que debe usar y ser coherentecon el tema elegido.

## Personaje principal
* Es el actor principal que tiene la responsabilidad de cumplir la misión definida, la mismaque estará asociada al objetivo para desarrollar 
las preguntas de cultura general.
* Puede tener vidas y/o poderes.
* Está representado por un conjunto de caracteres (Ascii Art) en consola, debe sercoherente con el contexto elegido.
* El movimiento puede ser por teclado o en forma automática.

## Aliados
* Son personajes que ayudan al personaje principal.
* El número de aliados es elegido por el equipo de trabajo.
* Están representados por un carácter o un conjunto de caracteres.
* El movimiento puede ser por teclado o en forma automática.
* Ayudan al personaje a responder la pregunta que se le muestra o poder cambiar la por otra.

## Enemigos
* Son personajes que impiden que el personaje principal cumpla su misión de responderlas preguntas planteadas por el equipo.
* El número de enemigos es elegido por el equipo de trabajo.
* Están representados por un conjunto de caracteres.
* El movimiento puede ser por teclado o en forma automática.
* Cada vez que un usuario colisione con un enemigo debe mostrar una pregunta de manera aleatoria, si responde bien gana cierta 
cantidad de puntos, si responde incorrectamentepierde una vida. Si las vidas llegan a 0 mostrar Mensaje PERDISTE.
* Si el personaje responde al menos 10 preguntas se le muestra la pantalla GANASTE.
  
## Dinámica del juego
A continuación, se muestran los pasos de cómo debe iniciar y desarrollarse el videojuego:
* El videojuego empieza con un Formulario de “PRESENTACIÓN”, puede contener un logodel equipo de trabajo.
* Animación de Formulario de Créditos o autores del juego.
* Debe incluir un menú de opciones para orquestar el accceso a: nueva partida, créditos,instrucciones, jugar, salir.
* Debe mostrar las instrucciones del videojuego.
* Durante el juego, el usuario debe tener toda la información visible en pantalla:Indicadores o variables que muestre los valores o 
estados del personaje principal, de losaliados y de los enemigos, las vidas, poderes y otros que el equipo de trabajo considere
pertinente.
* Mensaje de GANASTE (“You Win”) cuando se cumpla la condición de victoria (logro del objetivo)
* Mensaje de Perdiste (“Game Over”) cuando se cumpla la condición de derrota.

##**Diagrama de clases UML**
▪ Desarrollar el diagrama de clases UML de todas las clases, incluyendo atributos, métodos y relaciones entre clases, que se utilizarán en el videojuego.
