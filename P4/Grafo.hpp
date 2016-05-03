#ifndef GRAFO_HPP
#define GRAFO_HPP
	#include <vector>
	#include "Vertice.hpp"
	#include "Lado.hpp"
	class Grafo{
		private:
			std::vector<Vertice> vertices_;
			std::vector<std::vector<float>> matriz_;
			bool dirigido_;
		public:
			Grafo(bool dirigido):matriz_(0,vector<int>(0)){dirigido_=dirigido;};
	};
#endif
