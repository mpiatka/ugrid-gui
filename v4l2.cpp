#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

#include "v4l2.hpp"

std::vector<Camera> getCameras(){
	const int max = 64; //There can be only 64 /dev/videoN devices

	std::vector<Camera> result;

	int fd;
	struct v4l2_capability video_cap;

	for(int i = 0; i < max; i++){
		std::string path = "/dev/video" + std::to_string(i);
		if((fd = open(path.c_str(), O_RDONLY)) == -1){
			continue;
		}

		if(ioctl(fd, VIDIOC_QUERYCAP, &video_cap) == -1){
			continue;
		}

		Camera c;
		c.name = reinterpret_cast<const char*>(video_cap.card);
		c.path = path;

		result.push_back(c);

		close(fd);
	}

	return result;
}
