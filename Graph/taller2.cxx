#include <iostream>
#include <fstream>
#include <list>
#include <deque>
#include "Graph.h"
int main(int argc, char* argv[]){
  if(argc < 2){
    std::cout << "---------------------------" << std::endl;
    std::cout << "Archivo no indicado" << std::endl;
    std::cout << "---------------------------" << std::endl;
    return 1;
  }
  std::ifstream arch;
  arch.open(argv[1]);
  if(!arch){
    std::cout << "---------------------------" << std::endl;
    std::cout << "Archivo no pudo ser abierto correctamente" << std::endl;
    std::cout << "---------------------------" << std::endl;
    return 1;
  }
  std::string line;
  int grafoNum = 1, salida = -1;
  do{
    Graph<int>* grafo = new Graph<int>();
    int grado, origen, destino;
    if(salida != -1)
      grado = salida;
    else
      arch >> grado;
    for(int i = 0; i < grado; i++){
      grafo->addVertex(i);
    }
    do{
      arch >> origen >> destino;
      if(origen != -1 && destino != -1)
        grafo->addUndirectedEdge(origen,destino);
    }while(origen != -1 && destino != -1);
    std::cout << "El grafo " << grafoNum;
    std::list<std::deque<int>> connected = grafo->connectedComponents();
    if(connected.size() > 1)
      std::cout << " no" ;
    std::cout << " esta conectado. Tiene " << connected.size() << " componentes conectados." << std::endl;
    std::cout << "El grafo ";
    if(!grafo->EulerPathUndirected())
      std::cout << "no ";
    std::cout << "tiene camino y ";
    if(!grafo->EulerCircuitUndirected())
      std::cout << "no ";
    std::cout << "tiene circuito de Euler." << std::endl;
    arch >> salida;
    delete grafo;
    grafoNum++;
  }while(salida != -1);
  return 0;
}
