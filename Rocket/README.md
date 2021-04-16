# Metadados
 * **_Author: Raphael Lira dos Santos | RA: 223865_**
 * **_Author: Matheus Percário Bruder | RA: 222327_**
 * *Created at: 11/04/2021*
 * *File: "rocket.cpp"*

 ## Exercício 01 - Rocket
  Criar uma cena gráfica com a ilustração de um animal ou objeto em formato de malha triangular. A janela pode ter qualquer tamanho. Veja outros requisitos:
  1. O animal ou objeto deve possuir um "buraco";
  2. Os vértices do animal ou objeto podem estar em um arquivo txt ou no próprio programa C+OpenGL;
  3. A cena deve alternar entre a apresentação do animal ou objeto por meio de seu contorno ou com preenchimento; essa ação deve ser executada via clique do mouse em qualquer parte da cena.

 ### Explicação
  Nós optamos por criar a cena gráfica de um pinguim. Logo, para preencher os requisitos:
  1. As janelas do foguete vão ser os "buracos necessários";
  2. Os vértices dos triângulos que formam o foguete estarão no próprio programa;
  3. Execute o programa e clique sobre o foguete para alternar seu estado!

  Para estabelecer os vértices do foguete utilizamos a malha gráfica fornecida pelo professor, veja abaixo:

 | Malha - Contorno                          | Malha - Preenchida                             |
 | ----------------------------------------- | ---------------------------------------------- |
 | ![img-1](assets/images/foguete-malha.png) | ![img-1](assets/images/foguete-preenchido.png) |
  
  Ao todo existem XX triângulos, os quais devem possuir vértices semelhantes, então, utilizando alguns recursos da biblioteca OpenGL serão unificados, dando origem ao desenho do foguete. Veja o código abaixo para entender como os triângulos foram representados e preenchidos.

 ---
 ## Código fonte
 ```C++
 Código aqui!
 ```

 ---
 ## Formas de visualização
 A seguir, as duas formas de visualização:
 | Contorno                          | Preenchido                          |
 | --------------------------------- | ----------------------------------- |
 | ![img-1](assets/img/contorno.png) | ![img-1](assets/img/preenchido.png) |
