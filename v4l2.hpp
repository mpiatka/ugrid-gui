#ifndef V4L2_HPP
#define V4L2_HPP

#include <vector>
#include <string>

struct Camera{
	std::string name;
	std::string path;
};

std::vector<Camera> getCameras();



#endif
