# ortonormaliza-o-GramSchmidt
Universidade Federal da Fronteira Sul -UFFS
Curso de Ciência da Computação 
Nome: Jardel Anton
Matricula: 1311100022
Professor Antonio Neri
Disciplina de Algebra Linear - 2016/2

27/10/2016

Descrição do trabalho, disponível no moodle:{

	trabalho sobre ortogonalização
	por ANTONIO MARCOS CORREA NERI - quinta, 6 Out 2016, 19:10
		"Olá!

		Eu tinha dito que queria que vocês implementassem o método de Gram-Schmidt.

		Então eis como eu o quero:

		-Entrada:

		Deve ler o arquivo texto ortogonaliza.txt que terá as sete linhas como abaixo

		//Estes são os vetores que devem ser usados

		(1,2,3,4,5)

		(1,2,3,4,4)

		(1,1,3,4,3)

		(1,1,2,4,2)

		(1,1,1,1,1)

		Fim do arquivo

		 

		-Saída: deve me apresentar o resultado do processo no mesmo arquivo lido, logo abaixo da linha "fim do arquivo".

		 

		Observações.

		- O arquivo pode ter, eventualmente, vetores que não formam uma base. O programa deve decidir antes, se os vetores lidos são LI (se não forem, o que acontece com o programa?)

		- Eu só sei compilar em C e no linux. Então seu programa deve ter instruções sobre compilação se você fugir do padrão ou precisar de algo diferente.

		 

		- Você deve apresentar o exercício num arquivo compactado (zipado) com uma pasta contendo o código fonte do programa. Tanto a pasta quanto o arquivo zipado devem conter seu número de matrícula, seu nome e último sobrenome como no exemplo

		1049374937antonioneri.zip

		O nome do arquivo fonte deve ser programagram.c ou equivalente.

		Me pergunte neste tópico do fórum dúvidas sobre a apresentação.

		Até logo."
}



Compilação:
	usando gcc no linux, sem renomear o arquivo gerado:
		gcc programagram.c -lm

	usando gcc no linux, renomeando o arquivo gerado:
		gcc programagram.c -o programagram-lm


Executando o arquivo gerado:
	quando não renomeado o arquivo gerado:
		./a.out

	quando renomeado o arquivo gerado:
		./programagram

Arquivo de entrada:
	Nomeação:
		Conforme a descrição do trabalho, o arquivo será nomeado como 'ortogonaliza.txt', e seu conteudo será equivalente a:
		//Estes são os vetores que devem ser usados
		(1,2,3,4,5)
		(1,2,3,4,4)
		(1,1,3,4,3)
		(1,1,2,4,2)
		(1,1,1,1,1)
		Fim do arquivo

	Localização do arquivo de entrada:
		Para o programagram ler o arquivo, é necessário que ele esteja contido no mesmo diretório em que se encontra o arquivo gerado.
