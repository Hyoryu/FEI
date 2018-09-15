function mergeSort(array){
	try{ //garantir que o parâmetro enviado seja uma array.
		//verifica se a array passada é válida
		if(!array || array.length === 0){
			console.error("Array inválida: undefined ou null");
			return;
		}
		//caso base: array de um elemento
		if(array.length === 1)
			return array;
		
		let meio = Math.floor(array.length/2); //índice da metade da array

		/*array.slice
			1º parâmetro: início de onde vai dividir a array. 
			2º parâmetro (opcional): o índice final da divisão. O índice passado não será incluido!
			Se o 2º parâmetro for omitido, a array vai ser dividida do índice passado até o fim da array.
		*/
		let esquerda = array.slice(0, meio); // parte esquerda da array
		let direita = array.slice(meio);	 //parte direita da array

		return merge(mergeSort(esquerda), mergeSort(direita));
	}catch (erro){
		console.error(`Deu merda: ${erro}`);
	}
}

function merge(esquerda, direita){
	let fusao = [];
	let d = 0, e = 0;//índices de iteração dos lados direito e esquerdo.

	while(e < esquerda.length || d < direita.length){
		/*	
			IF
				Preenchimento com os elementos do lado direito:
				* "e" é igual a qtd de elementos do lado esquerdo (iterou tuto) OU
				* "d" E "e"¹ ainda não terminaram de iterar E direita[d] < esquerda[e]
				¹compararação de < ou > entre um valor e undefined vai resultar em false
			Else
				Preenchimento com os elementos do lado esquerdo:
				* "d" é igual a qtd de elementos do lado direito(terminou de iterar) OU
				* esquerda[e] < direita[d]
		*/
		if(e === esquerda.length || (d < direita.length &&  direita[d] < esquerda[e]) )
			fusao.push( direita[d++] );
		else
			fusao.push( esquerda[e++] );
	}
	return fusao;
}
