#include "open.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int Open::ouvrir( string chemin) {

    //verif chemin non vide
    if( chemin == "" ){
        cout <<" Merci de de pas donner un chemin vide." << endl;
        return -1;
    }

    //ouverture
    Mat image = imread(chemin, CV_LOAD_IMAGE_COLOR);

    //ouverture impossible
    if( !image.data ){
        cout <<  "L'image ne peut être ouverte" << std::endl ;
        return -1;
    }

    //affichage
    namedWindow( "Image", WINDOW_AUTOSIZE );
    imshow( "Image", image );

    waitKey(0);
    return 0;

}
