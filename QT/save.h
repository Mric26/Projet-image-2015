#ifndef SAVE_H
#define SAVE_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

using namespace std;

class Save
{
public:
    int sauv( cv::Mat im, string chemin);
};

#endif // SAVE_H
