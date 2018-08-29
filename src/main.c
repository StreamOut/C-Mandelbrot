#include <stdio.h>
#include <stdlib.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <GL/glu.h>

void algo3(int min_width, int min_height, int max_width, int max_height, int iterationMax){

  float x1 = -2.1;
  float x2 = 0.6;
  float y1 = -1.2;
  float y2 = 1.2;
  float image_x = max_width;
  float image_y = max_height;

  // on calcule la taille de l'image :
  float zoom_x = image_x/(x2 - x1);
  float zoom_y = image_y/(y2 - y1);

  for ( int x = min_width ;x < image_x ; x++){
      for(int y = min_height; y < image_y; y++){
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
              glBegin(GL_POINTS);
                 // glColor3f(255,255,255);
                 glColor3ub(x,y,0);
                 glVertex2i(x,y);
              glEnd();
              // drawColorPixel(d3.rgb(x,y,i), x, y, draw);
              // printf("x : %d y : %d \n",x,y);
            }
          else {
            glBegin(GL_POINTS);
               // glColor3f(255,255,255);
               glColor3ub(0,0,i);
               glVertex2i(x,y);
            glEnd();
            // drawColorPixel(d3.rgb(0,0 , i*255/iterationMax), x, y, draw);
          }
      }
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // printf("Key : %d == %d \n", key,GLFW_KEY_E);
    if (key == GLFW_KEY_E && action == GLFW_PRESS){
      printf("oki\n");
        glClear(GL_COLOR_BUFFER_BIT);
        algo3(0, 0, 640, 480, 500);
        glFlush();
      }
}

int initWindow(GLFWwindow* window){
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    gluOrtho2D( 0.0, 640.0, 480.0,0.0 );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glfwSetKeyCallback(window, &key_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

int main (int argc, char *argv[]){
    if(argc != 1){
      printf("Aucun argument n'est necessaire\nLes arguments suivant seront ignorés : \n" );
      for (int i = 1; i < argc; i++) {
        printf("\t - %s\n",argv[i]);
      }
    }
    GLFWwindow* window = NULL;
    initWindow(window);

    return 0;
}
