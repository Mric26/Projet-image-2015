#include "save.h"

int Save::sauv( cv::Mat im, string chemin ){

    imwrite( chemin, im );
    return 1;

}
