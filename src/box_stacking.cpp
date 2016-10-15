/**
 * @author     Marcos Alves
 * @date       14-10-2016
 */ 

#include "../inc/box_stacking.hpp"

int dynamic::box_stacking(const std::vector<dynamic::box>& boxes){
	// quantidade de caixas para utilização
	int len_boxes = boxes.size();
	
	// todas maneiras possiveis de se mexer na alterar a base da caixa
	// largura | altura | profundidade = 3 
	std::vector<box> ways;

	for(int i = 0 ; i < len_boxes ; ++i){
		// 1º maneira caixa original
		ways.push_back(boxes[i]);
		// 2º maneira altura <-> largura
		ways.push_back({boxes[i].width, boxes[i].height, boxes[i].depth});
		// 3º maneira altura <-> profundidade
		ways.push_back({boxes[i].depth, boxes[i].height, boxes[i].width});
	}
	
	// customizando função sort (função objeto)
	struct {
		// testando as areas das de duas caixas
		bool operator()(const box& a, const box& b){
			return a.depth * a.width > b.depth * b.width;
		}
	} compareTo;

	// ordenando em ordem decrescente as areas
	std::sort(ways.begin(), ways.end(), compareTo);
	
	// todas as alturas possíveis
	std::vector<int> max_stack_height;

	for(box b: ways)
		max_stack_height.push_back(b.height);
	
	// tamanho do array de todas as alturas
	int len_stack = max_stack_height.size();

	for(int i = 1 ; i < len_stack ; ++i){
		for(int j = 0 ; j < i ; ++j)
			if(ways[i].width < ways[j].width && ways[i].depth < ways[j].depth &&
			   max_stack_height[i] < max_stack_height[j] + ways[i].height){
	
				max_stack_height[i] = max_stack_height[j] + ways[i].height; 
			}
	}
	
	// calculo da máxima altura
	int max = *std::max_element(std::begin(max_stack_height), std::end(max_stack_height));

	return max;
}