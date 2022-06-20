#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

//Funcao para adicionar os barcos em posicoes aletorias
void adicionaBarcos(int m1[TAM][TAM], int m2[TAM][TAM]){
  
  for(int i=0; i<7; i++){
    int coluna = rand() %5, //Sorteia um numero entre 0 e 4 e atribui a variavel
        linha = rand() %5;

    if(m1[linha][coluna] == 0){
      m1[linha][coluna] = 1;
    }else{
      i--; //decrementando o i para manter a quantidade correta de barcos
    }
  }

  for(int i=0; i<7; i++){
    int coluna = rand () %5,
        linha = rand () %5;

    if(m2[linha][coluna] == 0){
      m2[linha][coluna] = 1;
    }else{
      i--;
    }
  }

}

//Funcao para desenhar o tabuleiro na tela
void desenharTabuleiro(int m1[TAM][TAM], int m2[TAM][TAM], int p1, int p2){

  printf("===================================\n| player 1: %d  -----  player 2: %d |\n===================================\n\n", p1, p2);
  
    printf("   1 2 3 4 5              1 2 3 4 5\n");
    for (int i = 0; i < TAM; i++) {
      printf("%d  ", i+1);
      for (int j = 0; j < TAM; j++) {
        int pos = m1[i][j];
        if(pos == 1 || pos == 0){
          printf("%c ", '~');
        } else if(pos == 2){
          printf("%c ", 'A');
        } else if(pos == 3){
          printf("%c ", 'F');
        }
      }
      printf("          ");

      printf("%d  ", i+1);
      for (int j = 0; j < TAM; j++) {
        int pos = m2[i][j];
      
        if(pos == 1 || pos == 0){
          printf("%c ", '~');
        } else if(pos == 2){
          printf("%c ", 'A');
        }else if(pos == 3){
          printf("%c ", 'F');
        }
      }
      printf("\n");
    } 

  printf("\n");
}

int main(void) {
  
  //Inicializando as matrizes e atribuindo o valor 0 em todas as posicoes
  int matrizp1[TAM][TAM] = {0}, 
      matrizp2[TAM][TAM] = {0};
  
  //Variveis auxiliares e de pontuacao
  int p1 = 0, p2 = 0, auxcol, auxlin;

  //Chamando as funcoes
  void desenharTabuleiro(), 
       adicionaBarcos();

  srand(time(NULL)); //Inicializando a funcao rand()

  adicionaBarcos(matrizp1, matrizp2);
  desenharTabuleiro(matrizp1, matrizp2, p1, p2);

  //Loop principal do jogo
  for(int i=1; p1 < 7 && p2 < 7;){
    
    printf("Jogador %d digite a coluna:  ", i);
    scanf("%d", &auxcol);
    printf("Jogador %d digite a linha:  ", i);
    scanf("%d", &auxlin);

    //Veificando se a coordenada e valida
    if(auxcol > 5 || auxlin >5 || auxcol < 1 || auxlin < 1){
      printf("\nEsta posicao não existe, jogue novamente.\n\n");
      continue;
    }

    //Subtraindo 1 das variaveis auxiliares para termos as posicoes de 0 a 4
    auxlin -= 1; 
    auxcol -= 1;

    if(i == 1){
      if(matrizp2[auxlin][auxcol] == 1){
        printf("\n");
        printf("BOMBA!!\n");
        matrizp2[auxlin][auxcol] = 3;
        printf("\n");
        p1+= 1;
      }else if(matrizp2[auxlin][auxcol] == 0){
        printf("\n");
        printf("Água =[\n");
        matrizp2[auxlin][auxcol] = 2;
        printf("\n");
      }else{
        printf("\n");
        printf("Você já jogou nesta posicao. Perdeu a vez :v");
        printf("\n");
      }

      
      i++; //incrementando o i para mudar de jogador
      
      desenharTabuleiro(matrizp1, matrizp2, p1, p2);
      
    }else{
      if(matrizp1[auxlin][auxcol] == 1){
        printf("\n");
        printf("BOMBA!!\n");
        matrizp1[auxlin][auxcol] = 3;
        p2+=1;
        printf("\n");
         
      }else if(matrizp1[auxlin][auxcol] == 0){
        printf("\n");
        printf("Água =[\n");
        matrizp1[auxlin][auxcol] = 2;
        printf("\n");
      }else{
        printf("\n");
        printf("Você já jogou nesta posicao. Perdeu a vez :v\n");
        printf("\n");
      }

      i--; //decrementando o i para mudar de jogador
      
      desenharTabuleiro(matrizp1, matrizp2, p1, p2);
    }
  }

  if(p1 > p2){
    printf("VITÓRIA DO PLAYER 1!!!");
  }else{
    printf("VITÓRIA DO PLAYER 2!!!");
  }

  
  return 0;
}