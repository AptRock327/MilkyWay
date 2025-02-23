#include <renderer.hpp>

void loadModel(const char* filename, std::vector<std::vector<float>>* verts, std::vector<std::vector<int>>* faces)
{
	std::ifstream in;
   	in.open (filename, std::ifstream::in);
	if (in.fail()) return;

	std::string line;
	while (!in.eof())
	{
        	std::getline(in, line);
        	std::istringstream iss(line.c_str());
        	char trash;
        	if (!line.compare(0, 2, "v "))
		{
            		iss >> trash;
            		std::vector<float> v;
			for (int i = 0; i < 3; i++) v.push_back(0.0);
            		for (int i=0; i<3; i++) iss >> v[i];
            		verts->push_back(v);
        	}
		else if (!line.compare(0, 2, "f "))
		{
            		std::vector<int> f;
            		int itrash, idx;
            		iss >> trash;
            		while (iss >> idx >> trash >> itrash >> trash >> itrash)
			{
                		idx--;
               			f.push_back(idx);
            		}
           		faces->push_back(f);
        	}
    	}
   	std::cout << "# v# " << verts->size() << " f# "  << faces->size() << std::endl;
}
