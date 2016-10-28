/********************************************
Universidade Federal da Fronteira Sul -UFFS
Curso de Ciência da Computação 
Nome: Jardel Anton
Matricula: 1311100022
Professor Antonio Neri
Disciplina de Algebra Linear - 2016/2
********************************************/

#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <math.h>

/*Função que faz a alocação de memória de ponteiro para ponteiro do tipo ponto flutuante. No programa é utilizado como matriz de pontos flutuantes. Tamanho l=linhas, c=colunas*/
float ** alocamatriz(int l, int c){
  int i, j; 
  float ** m = (float **)malloc(l * sizeof(float *)); 
  for (i = 0; i <  l; i++){
       m[i] = (float*) malloc(c * sizeof(float)); 
       for (j = 0; j <  c; j++)
            m[i][j] = 0; 
  }
	return m; 
}

/*Função que realiza o produto interno de dois vetores, o módulo do segundo e armazena em um vetor auxiliar, que é utilizado para fazer a subtração em projeção*/
void termo(float * aux, float * v, float * u){
	int a; 
	float m = 0, n = 0, f; 
	for(a = 0; a <  5; a++){
		m +=   u[a] * u[a]; 
		n +=   v[a] * u[a]; 
	}	
	m = sqrt(m); 
	f = n / m; 
	for(a = 0; a <  5; a++)
		aux[a] +=   (u[a] * f); 
}

/*A função termo realiza a projeção de v em u, projeção() realiza a subtração dos termos dos vetores da base original com os vetores projetados em aux, na função termo.*/
void projecao(float ** matriz){
	float ** aux; 
	int i, j; 
	for(i = 1; i <  5; i++){
		aux = alocamatriz(5, 5); 
		for(j = i; j > 0; j--)
			termo(aux[i], matriz[i], matriz[j - 1]); 
		for(j = 0; j <  5; j++)
			matriz[i][j] =  matriz[i][j] - aux[i][j]; 
		aux = NULL; 
	}
}

/*Função que realiza o calculo da norma de um vetor e altera a matriz base, armazenando o vetor normalizado*/
void norma(float ** v){
	int i , j; 
	float norm; 
	for(i = 0; i <  5; i++){
		norm = 0; 
		for(j = 0; j <  5; j++)
			norm +=   v[i][j] * v[i][j]; 
		norm = sqrt(norm); 
		for(j = 0; j <  5; j++)
			v[i][j] = v[i][j] / norm; 
	}
}

/*Realiza a leitura do arquivo de entrada, ignorando o texto na linha 1 e na linha 7, apenas lendo '(' e ',',operando a partir deles e lendo e armazenando os números.*/
void leitura(float ** m){
	FILE * f; 
	int c, i = -1, j = -1; 
	f = fopen("ortogonaliza.txt", "rw+"); 
	if(!f){
		printf("Ocorreu um erro ao abrir arquivo.\n"); 
		exit(1);
	}else{
		while((c = fgetc(f)) !=   EOF && i <  5){
			if(c  ==   '('){
				i++; 
				if(i  >=   5)
					break; 
				j = 0; 
				fscanf(f, "%f", &m[i][j]); 
			}
			if(c  == ','){				
				j++; 			
				fscanf(f, "%f", &m[i][j]); 
			}			
		}
	}	
	fclose(f); 
}

/*Realiza a escrita no arquivo, mesmo arquivo de entrada, informando a base ortonormalizada, ou se não foi possivel ortonormalizar ela.*/
void escrita(float ** m, int d){
	FILE * f; 
	int i, j; 
	f = fopen("ortogonaliza.txt", "a+"); 
	if(!f){
		printf("Ocorreu um erro ao abrir arquivo.\n"); 
		exit(1);
	}else{
		fprintf(f, "\n"); 
		if(d!=  0){
			fprintf(f, "%s", "Base ortonomalizada utilizando o processo de Gram-Schmidt.\n"); 
			for(i = 0; i < 5; i++){
				fprintf(f, "("); 
				for(j = 0; j < 5; j++){
					if(j ==  0){
						if(m[i][j] >=  0)
							fprintf(f, "  %.4f, ", m[i][j]); 
						else
							fprintf(f, " %.4f, ", m[i][j]); 
					}
					else if(j ==  4){
						if(m[i][j] >=  0)
							fprintf(f, "  %.4f)\n", m[i][j]); 
						else
							fprintf(f, " %.4f)\n", m[i][j]); 
					}
					else {
						if(m[i][j] >=  0)
							fprintf(f, "  %.4f, ", m[i][j]); 
						else
							fprintf(f, " %.4f, ", m[i][j]); 
					}
					
				}
			}
			printf("Base ortonomalizada escrita no final do arquivo entrada.\n"); 
		}else{
			fprintf(f, "%s", "Não é uma base. Pois os vetores são LD."); 
			printf("%s", "Não é uma base. Pois os vetores são LD.\n"); 
		}
	}
	
	fclose(f); 
}

/*Função que calcula a determinante de uma matriz 4x4. O conteúdo da função foi copiado de uma página da web: "http://www.hardware.com.br/comunidade/codigo-fazer-matriz/1069095/" */
int deter4(float ** matriz){
	int det4 = (matriz[0][0] * ((matriz[1][1]*matriz[2][2]*matriz[3][3]) + (matriz[1][2]*matriz[2][3]*matriz[3][1]) + (matriz[1][3]*matriz[2][1]*matriz[3][2])
          - ((matriz[1][2]*matriz[2][1]*matriz[3][3]) + (matriz[1][1]*matriz[2][3]*matriz[3][2]) + (matriz[1][3]*matriz[2][2]*matriz[3][1]) )))
         
          + ( (-matriz[0][1]) * ((matriz[1][0]*matriz[2][2]*matriz[3][3]) + (matriz[1][2]*matriz[2][3]*matriz[3][0]) + (matriz[1][3]*matriz[2][0]*matriz[3][0])
          - ((matriz[1][2]*matriz[2][0]*matriz[3][3]) + (matriz[1][0]*matriz[2][3]*matriz[3][2]) + (matriz[1][3]*matriz[2][2]*matriz[3][0]) )))
         
          + ( matriz[0][2] * ((matriz[1][0]*matriz[2][1]*matriz[3][3]) + (matriz[1][1]*matriz[2][3]*matriz[3][0]) + (matriz[1][3]*matriz[2][0]*matriz[3][1])
          - ((matriz[1][1]*matriz[2][0]*matriz[3][3]) + (matriz[1][0]*matriz[2][3]*matriz[3][1]) + (matriz[1][3]*matriz[2][1]*matriz[3][0]) )))
         
          + ((-matriz[0][3]) * ((matriz[1][0]*matriz[2][1]*matriz[3][2]) + (matriz[1][1]*matriz[2][3]*matriz[3][0]) + (matriz[1][3]*matriz[2][0]*matriz[3][1])
          - ((matriz[1][1]*matriz[2][0]*matriz[3][2]) + (matriz[1][0]*matriz[2][3]*matriz[3][1]) + (matriz[1][3]*matriz[2][1]*matriz[3][0]))));    
    return det4; 
}

/*Inicia o calculo da determinante usando cofatores, cada cofator tem uma matriz 4x4, que é lançada no deter4 e recebe a determinante calculada, devolvendo em seguida o determinante da matriz 5x5 */
float determinante(float ** matriz, int t){
	int i, j; 
	float det; 
	float ** nova1 = alocamatriz(4, 4); 
	float ** nova2 = alocamatriz(4, 4); 
	float ** nova3 = alocamatriz(4, 4); 
	float ** nova4 = alocamatriz(4, 4); 
	float ** nova5 = alocamatriz(4, 4); 	
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			nova1[i][j] = matriz[i+1][j+1]; 
		}
	}
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j >=  2)
			nova2[i][j] = matriz[i+1][j+1]; 
			else 
				nova2[i][j] = matriz[i+1][j]; 
		}

	}
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j >=  3)
				nova3[i][j] = matriz[i+1][j+1]; 
			else 
				nova3[i][j] = matriz[i+1][j]; 
		}

	}
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j >=  4)
				nova4[i][j] = matriz[i+1][j+1]; 
			else 
				nova4[i][j] = matriz[i+1][j]; 
		}

	}
	for(i = 0; i < 4; i++){
		for(j = 0; j < 5; j++){
			nova5[i][j] = matriz[i+1][j]; 
		}
	}
	det = matriz[0][0]*deter4(nova1) - matriz[0][1]*deter4(nova2) + matriz[0][2]*deter4(nova3) - matriz[0][3]*deter4(nova4)+matriz[0][4]*deter4(nova5); 
	return det; 
}

/*Função principal, faz a declaração da matriz inicial, chamando as funções acima para fazer as operações*/
int main(){	
	printf("\n\n"); 
	float ** m; 
	m =  alocamatriz(5, 5); 
	if(!m){
		printf("Erro na memoria.\n"); 
		return 0; 
	}
	leitura(m); 	
	if(m[0] ==  NULL){
		printf("Verifique se o arquivo de entrada tem 5 vetores.\n"); 
		return 0; 
	}
	if(determinante(m, 5)!=   0 ){
		projecao(m); 
		norma(m); 
		escrita(m, 1); 		
	}else
		escrita(m, 0); 
	printf("\n"); 
	return 0; 
}
