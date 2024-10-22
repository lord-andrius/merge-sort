#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void merge(int array[], size_t tamanho) {
	
	//condição de parada
	if(tamanho < 2) {
		return;
	}

	size_t tamanho_parte1, tamanho_parte2;

	if(tamanho % 2 == 0) {
		tamanho_parte1 = tamanho_parte2 = tamanho / 2;
	} else {
		tamanho_parte2 = tamanho / 2;
		tamanho_parte1 = tamanho_parte2 + 1;

		/// só checando se a lógica da divisão está certa
		assert((tamanho_parte1 + tamanho_parte2) == tamanho);
	}

	int *parte1 = array;
	int *parte2 = &array[tamanho_parte1];

	merge(parte1, tamanho_parte1);
	merge(parte2, tamanho_parte2);

	// fazendo o merge de fato
	for(size_t c = 0; c < tamanho_parte2; c++) {
		int onde_devo_inserir = tamanho_parte1;
		int numero_a_ser_inserido = parte2[c];
		for(size_t c2 = 0; c2 < tamanho_parte1; c2++) {
			if(parte1[c2] > numero_a_ser_inserido) {
				onde_devo_inserir = c2;
				break;
			}
		}

		// uma garantia de lógica
		assert(onde_devo_inserir <= tamanho_parte1);

		// movendo os elementos da frente para poder inserir
		// para inserir no meio de um vetor temos que mover
		// os elementos para frente
		if(onde_devo_inserir != tamanho_parte1) {
			int valor_para_inserir = parte1[onde_devo_inserir];
			for(int c = onde_devo_inserir; c < tamanho_parte1; c++) {
				int tmp = parte1[c + 1];
				parte1[c + 1] = valor_para_inserir;
				valor_para_inserir = tmp;
			}

		} 
		parte1[onde_devo_inserir] = numero_a_ser_inserido;
		tamanho_parte1++;
	}
		
}

int main(void) {
	int x[] = {
			 46,
			 23,
			 44,
			 83,
			 71,
			  2,
			 58,
			 94,
			  7,
			 51,
	};
	
	for(int i = 0; i < sizeof(x)/sizeof(int); i++) printf("%d ", x[i]);
	puts("");
	merge(x, 10);
	for(int i = 0; i < sizeof(x)/sizeof(int); i++) printf("%d ", x[i]);
	return 0;
}
