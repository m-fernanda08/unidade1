#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

//funções para os vetores
void inser_vet_alet(int vetor[], int n); //inserir vetor aleatorio
void exib_vet(int vetor[], int n); //exibir o vetor
void ord_vet_cresc(int vetor[], int n); //ordena o vetor em ordem crescente
void ord_vet_decres(int vetor[], int n); //ordena o vetor em ordem decrescente
int busc_vet(int vetor[], int n, int element);

//funções para as matrizes
void inser_mat_alet(int matriz[MAX][MAX], int lines, int columns);
void exib_mat(int matriz[MAX][MAX], int lines, int columns);
void ord_lines_mat_cresc(int matrix[MAX][MAX], int lines, int columns);
void ord_lines_mat_decres(int matrix[MAX][MAX], int lines, int columns);
int busc_mat(int matriz[MAX][MAX], int lines, int columns, int element);

int main(){
    srand(time(NULL));

    int vetor[MAX], matriz[MAX][MAX];
    int n = 10, lines = 3, columns = 3;
    int element, position;

    //operações com vetor
    inser_vet_alet(vetor, n);
    printf("vetor com valor original: \n");
    exib_vet(vetor, n);

    //busca elemento no vetor
    element = vetor[2]; //usa o 3º elemento para teste
    position = busc_vet(vetor, n, element);
    printf("buscando o elemento %d no vetor...", element);
    if(position != -1){
        printf("elemento encontrado na posição %d\n", position);
    }else{
        printf("elemento não encontrado no vetor\n");
    }

    //ordenar o vetor em ordem crescente
    ord_vet_cresc(vetor, n);
    printf("vetor ordenado em ordem crescente: \n");
    exib_vet(vetor, n);

    //ordenar o vetor em ordem decrescente
    ord_vet_decres(vetor, n);
    printf("vetor ordenado em ordem decrescente: \n");
    exib_vet(vetor, n);

    //operações com matriz 
    inser_mat_alet(matriz, lines, columns);
    printf("matriz com valor original: \n");
    exib_mat(matriz, lines, columns);

    //buscar elemento na matriz
    element = matriz[1][1]; //usa o elemento do meio da matriz
    printf("buscando o elemento %d na matriz...", element);
    position = busc_mat(matriz, lines, columns, element);
    if(position != -1){
        printf("elemento encontrado na matriz\n");
    }else{
        printf("elemento não encontrado na matriz\n");
    }

    //ordenar linhas da matriz em ordem crescente
    ord_lines_mat_cresc(matriz, lines, columns);
    printf("matriz com suas linhas ordenadas em ordem crescente: \n");
    exib_mat(matriz, lines, columns);

    //ordenar linhas da matriz em ordem decrescente
    ord_lines_mat_decres(matriz, lines, columns);
    printf("matriz com linhas ordenadas em ordem decrescente: \n");
    exib_mat(matriz, lines, columns);
    
    return 0;
}   

//funções para vetores
void inser_vet_aleat(int vetor[], int n){
    for(int i = 0; i < n; i++){
        vetor[i] = rand() % 100;
    }
}

void exb_vet(int vetor[], int n){
    for(int i = 0; i < n; i++){
        printf("%d", vetor[i]);
    }
    printf("\n");
}

void ord_vet_cresc(int vetor[], int n){
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n; j++){
            if(vetor[i] > vetor[j]){
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

void ord_vet_decres(int vetor[], int n){
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j= i + 1; j < n; j++){
            if(vetor[i] < vetor[j]){
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int busc_vet(int vetor[], int n, int element){
    for(int i = 0; i < n; i++){
        if(vetor[i] == element){
            return i;
        }
    }
    return -1;
}

//funções para as matrizes
void inser_mat_aleat(int matriz[MAX][MAX], int lines, int columns){
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            matriz[i][j] = rand() % 100; //valores aleatórios de 0 a 99
        }
    }
}

void exb_mat(int matriz[MAX][MAX], int lines, int columns){
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

void ord_lines_mat_cresc(int matriz[MAX][MAX], int lines, int columns){
    for(int i = 0; i < lines; i++){
        ord_vet_cresc(matriz[i], columns);
    }
}

void ord_lines_mat_decres(int matriz[MAX][MAX], int lines, int columns){
    for(int i = 0; i < lines; i++){
        ord_vet_decres(matriz[i], columns);
    }
}

int busc_mat(int matriz[MAX][MAX], int lines, int columns, int element){
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            if(matriz[i][j] == element){
                return 1; //elemento encontrado
            }
        }
    }
    return -1; //elemento não encontrado
}