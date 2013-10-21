#include "CImg.h"
  using namespace cimg_library;

  int main() {
    CImg<unsigned char> image("lena.jpg"), MyImage(500,400,1,3,0);
//    CImg<unsigned char> MyImage(300,200,1,3,0);
//    const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
//    image.blur(2.5);
//    while (!main_disp.is_closed && !draw_disp.is_closed) {
    unsigned width = MyImage.dimx();  // access image width
    unsigned height = MyImage.dimy(); // access image height
//   Sometimes it is necessary to initialize the image, such that all pixels have a particular value. This can be
//   achieved by the function call
     MyImage.fill(0.0f);
//   which, in this example, sets every pixel to zero.
//   As already mentioned, the access of the pixels is intuitively like one would access a 2-dimensional array, i.e.
     for (unsigned y=0; y < height; y++) {
        for (unsigned x=0; x < width; x++) {
          MyImage(x,y) = x*y;
        }
     }
    CImgDisplay main_disp(MyImage,"Click a point");//, draw_disp(visu,"Intensity profile");
    main_disp.wait(10000);
//      if (main_disp.button && main_disp.mouse_y>=0) {
//        const int y = main_disp.mouse_y;
//        visu.fill(0).draw_graph(image.get_crop(0,y,0,0,image.dimx()-1,y,0,0),red,1,1,0,255,0);
//        visu.draw_graph(image.get_crop(0,y,0,1,image.dimx()-1,y,0,1),green,1,1,0,255,0);
//        visu.draw_graph(image.get_crop(0,y,0,2,image.dimx()-1,y,0,2),blue,1,1,0,255,0).display(draw_disp);
//       }
//      }
  return 0;
  }
