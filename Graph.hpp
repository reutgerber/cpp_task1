//322516840
//reutgerber@gmail.com

#ifndef __graph__hpp__
#define __graph__hpp__

using namespace std;
#include <vector>

namespace ariel
{
	class Graph
	{
	private:
		int _veritx_num;
		int _edges_num = 0;
		bool _symetric = false;
		vector<vector<int>> matrix;

	private:
		vector<bool> _vis1;
		void CheckSymetric();
		

	public:
		bool IsDirected()
		{
			return !_symetric;
		}
		bool connected(int x, int y);
		int weight(int x, int y);
		int get_num_of_vertex() {
			return _veritx_num;
		}

		void loadGraph(vector<vector<int>> matrix);
		void printGraph();
		
		

	};
}
#endif