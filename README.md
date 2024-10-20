# This is part of an execise that I made named Campo Minado

Descrição acerca do funcionamento do jogo “Campo minado “
Sarah Campos Fernandes Lima

Instituto de Computação – Universidade Federal do Amazonas (UFAM)
Manaus – AM – Brazil
sarah.lima@icomp.ufam.edu.br

Abstract. This article refers to the C program that originates the game
“Campo minado” describing the objective and functioning of each function
present in its scope.

Resumo. Este artigo refere-se ao programa em C que origina o jogo “Campo
minado” descrevendo o objetivo e funcionamento de cada função presente em
seu escopo.

1. Explicação acerca do funcionamento geral do jogo
O jogo apresenta um “tabuleiro” que consiste em uma matriz com todas as suas
posições inicializadas com o caractere ‘x’, onde o jogador deve digitar
coordenadas evitando sempre que essas coordenadas sejam as das minas, que
estão ocultas para o jogador. O objetivo do jogo é que o usuário acesse todas as
casas da matriz sem acertar as minas.
O jogador perde caso ele acerte alguma das minas presentes no tabuleiro.

2. Descrição das funções do jogo
Explicação do objetivo e escopo de cada método implementado.

2.1. Função “gameLevel”
Tem como objetivo ler o nível escolhido pelo jogador e com base nisso, cria o tabuleiro
com tamanho, número de minas e número de jogadas de forma adequada.
Recebe como parâmetro o número de linhas e colunas da matriz de caracteres
(tabuleiro), assim como o número de minas presente no mesmo e o número de jogadas
que o jogador possui (todos inicialmente com valor igual a zero), sendo estes do formato
de ponteiros do tipo inteiro. De modo que em função do nível que o jogador escolher,
essas variáveis são inicializadas com seus respectivos valores.

2.2. Função “newMatrix”
Tem como objetivo criar e inicializar uma matriz de caracteres alocada dinamicamente.
Recebe como parâmetro o número de linhas e colunas da matriz de caracteres, já
com os valores devidos (alterados no método “gameLevel”). Por fim, a matriz tem todos
os seus elementos preenchidos com o valor de ‘x’ e retorna o endereço do primeiro
elemento do tabuleiro.

2.3. Função “printMatrix”
Tem como objetivo imprimir a matriz de caracteres (tabuleiro).
Recebe como parâmetro o número de linhas e colunas da matriz de caracteres, já
com os valores devidos (alterados no método “gameLevel”), e também o endereço do
primeiro elemento da matriz de caracteres. Este método percorre cada elemento desta
matriz, imprimindo-os.

2.4. Função “createMines”
Tem como objetivo criar uma matriz “gabarito” que possui a mesma dimensão do
tabuleiro, de modo a inicializá-la com minas cujo as coordenadas foram sorteadas de
forma aleatória.
Recebe como parâmetro o número de linhas e colunas da matriz de caracteres,
assim como o número de minas que o tabuleiro deve ter. Com base nisso, a função cria
a matriz gabarito e a preenche com o valor -1, caso seja a posição de uma mina.
Posteriormente, retorna o endereço do primeiro elemento da matriz gabarito nomeada
“mines”.

2.5. Função “minesProx”
Tem como objetivo calcular o número de minas próximas à posição escolhida pelo
jogador .
Recebe como parâmetro o número de linhas e colunas da matriz de caracteres, as
coordenadas X e Y escolhidas pelo jogador, assim como o endereço do primeiro
elemento da matriz gabarito. Com base nisso, dentro de dois laços de repetição que
percorrem a matriz, usa-se a fórmula de cálculo da distância entre dois pontos, sendo
estes a coordenada da posição atual do elemento da matriz e a coordenada do jogador.
Caso na posição atual do ciclo esteja uma mina, ele verifica se a distância entre essa
mina e a coordenada do jogador é igual a um, caso a afirmação seja verdadeira, ele
soma mais um no valor da variável “qntdMines” (cujo valor inicialmente era igual a
zero). Posteriormente, é retornado o valor desta variável .

2.6. Função “modifyMat”
Tem como objetivo modificar os elementos da matriz tabuleiro em função das
coordenadas digitadas pelo jogador.
Recebe como parâmetro o número de linhas e colunas da matriz de caracteres, a
coordenada X e Y escolhida pelo jogador, assim como o número de minas próximas à
essa coordenada. Dado essas informações, ela preenche a posição de coordenada X e Y
com o número de minas próximas a essa posição (com distância de uma “casa” ). Por
fim, a função retorna o endereço do primeiro elemento da matriz tabuleiro já atualizada,
informando o número de minas vizinhas.

2.7. Função “finalTemplate”
Tem como objetivo modificar os elementos da matriz gabarito em função das
coordenadas das minas, somando mais um ao valor dos elementos vizinhos à elas.
Recebe como parâmetro o número de linhas e colunas da matriz de caracteres, o
número de minas presente no tabuleiro, e a coordenada do primeiro elemento da matriz
gabarito. Dadas essas informações, por meio de dois laços “for”, percorre-se a matriz
gabarito. Caso um elemento da matriz gabarito tenha valor igual a menos um (valor que
indica que a referida casa tem uma mina), todas as casas vizinhas à essa mina tem seu
valor somado mais um, por meio de dois laços “for”, percorremos todos os elementos
vizinhos a esta mina, somando mais um ao valor destes elementos.

2.8. Função “printTemplate”
Tem como objetivo imprimir a matriz gabarito após o jogo ser finalizado, seja o jogador
vencedor, ou não.
Recebe como parâmetro o número de linhas e colunas da matriz de caracteres, e
também o endereço do primeiro elemento da matriz gabarito. Este método percorre cada
elemento desta matriz, imprimindo-os.

2.9. Função “gameOver”
Tem como objetivo verificar se a coordenada escolhida pelo jogador é igual à
coordenada de uma mina.
Recebe como parâmetro o número de colunas da matriz de caracteres, o
endereço do primeiro elemento da matriz gabarito, número de jogadas que o jogador
possui, bem como as coordenadas X e Y escolhidas pelo jogador. Este método verifica
se a coordenada escolhida pelo jogador é igual à da mina, caso seja, ela retorna o valor
1, caso não sejam iguais, retorna o valor 0.

2.9.1 Função “main”
Tem como objetivo chamar cada função, de acordo com suas demandas, conta o número
de jogadas já executadas, e também imprime as informações do jogo.

3. Instruções de uso
O usuário deve compilar o arquivo do jogo no seguinte formato : “gcc
campo_minado_sarah_lima.c -lm ”, no terminal de sua escolha. Depois, o usuário
deve executar o arquivo usando o comando padrão linux “./a.out”. Feito isso,
aparecerão as seguintes informações: as regras de jogo e os níveis de dificuldade
presentes no jogo.
