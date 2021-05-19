#include <GLFW/glfw3.h>
#include <cmath>
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1200, 320, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);

        glClearColor(0.0, 0.0, 0.0, 1.0);  // clear background with black
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        double w = 1200;
        double h = 320;
        double ar = w / h;          //  1200/320 = 3.75

        //  Variables for Ortho
        double left = ar * -360;    //  3.75 * (-360) = -1350
        double right = ar * 360;    //  3.75 * (360)  = 1350

        glOrtho(left, right, -120, 120, -1, 1);

        //  DRAW A GRID

        int rows = 10;
        int columns = 10;

        glBegin(GL_LINES);

        glColor3f(0.0, 0.22, 0.15);

        //  HORIZONTAL LINES
        for (int i = 0; i < rows; i++)
        {
            glVertex2f( left, 120 - ( i * 30 ) );
            glVertex2f( right, 120 - ( i * 30 ) );
        }

        //  VERTICAL LINES
        for (int y = 0; y < columns; y++)
        {
            glVertex2f( right - (y * 270), left );
            glVertex2f( right - (y * 270), right );
        }


        //glVertex2f(0, -120);
        //glVertex2f(0, 120);


        //glVertex2f(60, -120);
        //glVertex2f(60, 120);


        //glVertex2f(120, -120);
        //glVertex2f(120, 120);

        glEnd();

        //  DRAW SIN WAVE

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glPointSize(10);
        glColor3f(1.0, 0.0, 0.0);

        glBegin(GL_POINTS);
        for (int i = 0; i < 361; i = i + 5)
        {
            float x = (float)i;
            float y = 100.0 * sin(i * (6.284 / 360.0));
            glVertex2f(x, y);
        }
        glEnd();

        //glutSwapBuffers();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}