/*
  Grafo No dirigido-> ingresar Datos en addUndirectedEdge();
  1->connectedComponents del Graph
  2->connectedComponents del Graph
  3->EulerCircuit y EulerPath del Graph
 */
#include <iostream>
#include "Graph.h"
int main(int argc, char* argv[]){
  Graph<int>* grafo = new Graph<int>();
  for(int i = 1; i < 9; i ++){
    grafo->addVertex(i);
  }
  for(typename std::deque<GraphNode<int>>::iterator it = grafo->getNodes().begin(); it != grafo->getNodes().end(); it ++){
    std::cout << "Dato: " << it->getData()<< std::endl;
  }
  int i = 1, j = 2, k = 3, y = 4, m = 5, n = 6, o = 7;
  int q = 7, w = 8, e = 9;
  grafo->addEdge(i,j,j);
  grafo->addEdge(i,n,n);
  grafo->addEdge(j,k,e);
  grafo->addEdge(j,y,o);
  grafo->addEdge(j,n,k);
  grafo->addEdge(n,y,k);
  grafo->addEdge(n,o,y);
  grafo->addEdge(k,m,k);
  grafo->addEdge(y,k,y);
  grafo->addEdge(o,m,w);
  grafo->addEdge(m,o,k);
  for(typename std::deque<GraphNode<int>>::iterator it = grafo->getNodes().begin(); it != grafo->getNodes().end(); it ++){
    std::cout << "Dato: " << it->getData()<< std::endl;
    for(typename std::deque<AdyacentNode<int>>::iterator it2 = it->getAdyacentNodes().begin(); it2 != it->getAdyacentNodes().end(); it2++){
      std::cout << "\tAdyacente: " << it2->getData() << std::endl;
    }
  }
  if(grafo->findEdge(i,k))
    std::cout << "Vertice Existe" << std::endl;
  else
    std::cout << "Vertice No Existe" << std::endl;
  if(grafo->findEdge(i,j))
    std::cout << "Vertice Existe" << std::endl;
  else
    std::cout << "Vertice No Existe" << std::endl;
  for(typename std::deque<GraphNode<int>>::iterator it = grafo->getNodes().begin(); it != grafo->getNodes().end(); it ++){
    std::cout << "Dato: " << it->getData()<< std::endl;
    for(typename std::deque<AdyacentNode<int>>::iterator it2 = it->getAdyacentNodes().begin(); it2 != it->getAdyacentNodes().end(); it2++){
      std::cout << "\tAdyacente: " << it2->getData() << " Peso: " << it2->getWeight()<<std::endl;
    }
  }
  std::cout << "----------------------------------------------------" <<  std::endl;
  std::cout << "----------------------------------------------------" <<  std::endl;
    grafo->flatCourse();
    std::cout << "----------------------------------------------------" <<  std::endl;
    std::cout << "\tDepth First Course" << std::endl;
    std::deque<int> DF = grafo->depthFirst(i);
    for(typename std::deque<int>::iterator iterador = DF.begin(); iterador != DF.end(); iterador++)
      std::cout << *iterador << " ";
    std::cout << std::endl;
    std::cout << "----------------------------------------------------" <<  std::endl;
    std::cout << "\tBreath First Course" << std::endl;
    std::deque<int> BF = grafo->breadthFirst(i);
    for(typename std::deque<int>::iterator iterador = BF.begin(); iterador != BF.end(); iterador++)
      std::cout << *iterador << " ";
    std::cout << std::endl;
    std::cout << "----------------------------------------------------" <<  std::endl;
    std::cout << "\tConnected Components" << std::endl;
    std::list<std::deque<int>> connected = grafo->connectedComponents();
    for(typename std::list<std::deque<int>>::iterator iteradorLista = connected.begin(); iteradorLista != connected.end(); iteradorLista++){
      for(typename std::deque<int>::iterator iteradorDeque = iteradorLista->begin(); iteradorDeque != iteradorLista->end(); iteradorDeque++){
        std::cout << *iteradorDeque << " ";
      }
      std::cout << std::endl;
    }
    std::cout << "----------------------------------------------------" <<  std::endl;
    std::cout << "\tStrong Connected Components" << std::endl;
    std::deque<int> strongConnection = grafo->strongConnection(i);
    for(typename std::deque<int>::iterator iteradorDeque = strongConnection.begin(); iteradorDeque != strongConnection.end(); iteradorDeque++){
      std::cout << *iteradorDeque << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------------" <<  std::endl;
    std::cout << "\tStrong Connected Components" << std::endl;
    std::list<std::deque<int>> connectedComponents = grafo->allStrongConnections();
    for(typename std::list<std::deque<int>>::iterator iteradorLista = connectedComponents.begin(); iteradorLista != connectedComponents.end(); iteradorLista++){
      for(typename std::deque<int>::iterator iteradorDeque = iteradorLista->begin(); iteradorDeque != iteradorLista->end(); iteradorDeque++){
        std::cout << *iteradorDeque << " ";
      }
      std::cout << std::endl;
    }
    std::cout << "----------------------------------------------------" <<  std::endl;
    std::cout << "\tEuler Circuit" << std::endl;
    if(grafo->EulerCircuit())
      std::cout << "Si hay" << std::endl;
    else
      std::cout << "No Hay" << std::endl;
    std::cout << "----------------------------------------------------" <<  std::endl;
    std::cout << "\tEuler Path" << std::endl;
    if(grafo->EulerPath())
      std::cout << "Si hay" << std::endl;
    else
      std::cout << "No Hay" << std::endl;
    std::cout << "----------------------------------------------------" <<  std::endl;
    std::cout << "Total Peso: " << grafo->allWeights() << std::endl;
    std::cout << "----------------------------------------------------" <<  std::endl;
    std::map<int, AdyacentNode<int>>* Dijks = grafo->Dijkstra(i);
    for(typename std::deque<GraphNode<int>>::iterator it = grafo->getNodes().begin(); it != grafo->getNodes().end(); it ++){
      std::cout << "Nodo: " << it->getData() << " Viene de: " << (*Dijks)[it->getData()].getData() << " con un peso de: " << (*Dijks)[it->getData()].getWeight() << std::endl;
    }
    std::cout << "----------------------------------------------------" <<  std::endl;
    std::map<int, AdyacentNode<int>*>* Prim = grafo->Prim(i);
    for(typename std::deque<GraphNode<int>>::iterator it = grafo->getNodes().begin(); it != grafo->getNodes().end(); it ++){
      std::cout << "Nodo: " << it->getData() << " Viene de: " << (*Prim)[it->getData()]->getData() << " con un peso de: " << (*Prim)[it->getData()]->getWeight() << std::endl;
    }
    delete grafo;
  return 0;
}
