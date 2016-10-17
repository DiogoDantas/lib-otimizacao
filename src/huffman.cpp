/**
 * @author     Marcos Alves
 * @date       15-10-2016
 */
#include "../inc/huffman.hpp" // greedy::code_puts,  greedy::huff_encode

void greedy::code_puts(greedy::node_t* root, std::string code){
	// testando se a raíz é nula
	if(!root) return;

	// verificando se o conteúdo do nó é um caracter valido
	// # -> significa nulo
	if(root->content != '#')
		std::cout << root->content << ": " << code << std::endl;

	// recursivamente a esquerda é 0 e a direita é 1
	// concatenando com o que já tem ao longo do percorrimento
	code_puts(root->left, code + "0");
	code_puts(root->right, code + "1");
}

greedy::node_t* greedy::huff_encode(const std::vector<char>& ch, const std::vector<int>& freq){
	// quantidade de caracters
	int len = ch.size();
	// ponteiros auxiliares
	node_t *left = nullptr, *right = nullptr, *root = nullptr;

	// função objeto de comparação
	// sobrecarga de operador na struct node_t aparentemente não estava fazendo efeito
	struct compare {
	    bool operator()(node_t* lhs, node_t* rhs) {
	        return rhs->frequency < lhs->frequency;
	    }
	};
	// heap minima
	std::priority_queue<node_t*, std::vector<node_t*>, compare> min_heap;

	// inserindo caracters e suas frenquencias
	for(int i = 0 ; i < len ; ++i)
		min_heap.push(new node_t(ch[i], freq[i]));
	

	while(min_heap.size() != 1) {
		// pegando os dois de menores frequência
		left = min_heap.top();
		min_heap.pop();

		right = min_heap.top();
		min_heap.pop();

		// gerando um novo nó para inserir na min_heap
		// '#' -> indica que esse nó é nulo na hora do print
		// 		#
		// 	  /  \
		// 	 c    b
		// lembrando que não necessariamente um '#' tem seus filhos sendo caracters.
		root = new node_t('#', left->frequency + right->frequency, left, right);
		min_heap.push(root);
	}
	return min_heap.top();
}

