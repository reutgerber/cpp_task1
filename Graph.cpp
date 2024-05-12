//322516840
//reutgerber@gmail.com

#include "Graph.hpp"
#include <stdexcept>
using namespace ariel;

/*
void Graph::CheckSymetric()
{
	for (int i = 0; i < matrix.size(); i++)
		for(int j=i+1;j< matrix.size();j++)
	{
			if (matrix[i][j] != matrix[j][i])
			{
				_symetric = false;
				return;
			}
	}
	_symetric = true;



}*/
void Graph::CheckSymetric()
{
    for (std::vector<int>::size_type i = 0; i < matrix.size(); i++)
    {
        for (std::vector<int>::size_type j = i + 1; j < matrix.size(); j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                _symetric = false;
                return;
            }
        }
    }
    _symetric = true;
}


void Graph::loadGraph(vector<vector<int>> matrix)
{
	if (matrix.size() != matrix[0].size())
		throw(std::invalid_argument("Invalid graph : The graph is not a square matrix.\n"));
	this->matrix = matrix;
	_veritx_num = matrix.size();
	_edges_num = 0;
	for (std::vector<int>::size_type i = 0; i < matrix.size(); i++)
	{
		for (std::vector<int>::size_type j = 0; j < matrix[0].size(); j++)
		{
			
			if (matrix[i][j] != 0)
				_edges_num++;

		}

	}
	CheckSymetric();

}

int Graph::weight(int x, int y)
{
	return matrix[x][y];
}


bool Graph::connected(int x, int y)
{
	if (matrix[x][y] != 0)
		return true;
	return false;
}




void Graph::printGraph()
{
	_veritx_num = matrix.size();
	_edges_num = 0;
	for (std::vector<int>::size_type i = 0; i < matrix.size(); i++)
	{
		for (std::vector<int>::size_type j = 0; j < matrix[0].size(); j++)
		{
			printf("%5d", matrix[i][j]);
	
		}
		printf("\n");
	}
	printf("Graph with %d vertices and %d edges.\n", _veritx_num, _edges_num);

}