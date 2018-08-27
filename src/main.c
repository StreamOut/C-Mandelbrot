#include <stdio.h>
#include <stdlib.h>

void algo3(int width, int height, int iterationMax, int draw){

  float x1 = -2.1;
  float x2 = 0.6;
  float y1 = -1.2;
  float y2 = 1.2;
  float image_x = width;
  float image_y = height;

  // on calcule la taille de l'image :
  float zoom_x = image_x/(x2 - x1);
  float zoom_y = image_y/(y2 - y1);

  for ( int x = 0 ;x < image_x ; x++){
      for(int y = 0; y < image_y; y++){
          float c_r = x / zoom_x + x1;
          float c_i = y / zoom_y + y1;
          float z_r = 0;
          float z_i = 0;
          int i = 0;

          do{
              float tmp = z_r;
              z_r = z_r*z_r - z_i*z_i + c_r;
              z_i = 2*z_i*tmp + c_i;
              i = i+1;

            }    while (z_r*z_r + z_i*z_i < 4 && i < iterationMax);

          if (i == iterationMax){
              // drawColorPixel(d3.rgb(x,y,i), x, y, draw);
              printf("x : %d y : %d \n",x,y);
            }
          else {
            // drawColorPixel(d3.rgb(0,0 , i*255/iterationMax), x, y, draw);
          }
      }
    }
}

int main (int argc, char *argv[]){
  algo3(240, 240, 50, 0);
}
