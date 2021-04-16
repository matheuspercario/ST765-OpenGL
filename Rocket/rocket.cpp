#include <GL/glut.h>
#include <stdlib.h>

// prototipos das funcoes
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

// funcao principal
int main(int argc, char** argv){
  glutInit(&argc, argv);                         // inicializa o glut
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  // especifica uso de cores e buffers
  glutInitWindowSize (600, 600);                 // especifica as dimensoes da janela
  glutInitWindowPosition (100, 100);             // especifica aonde a janela aparece na tela
  glutCreateWindow ("Desenhando um Foguete");     // cria a janela
  init();
  glutDisplayFunc(display);               // funcao que sera redesenhada pelo GLUT
  glutKeyboardFunc(keyboard);             // funcoes de teclado
  glutMainLoop();                         // mostra todas as janelas criadas
  return 0;
}

// definicao de cada funcao

void init(void){
  glClearColor(0.0, 0.0, 0.0, 1.0);    // cor de fundo 
  glOrtho(0, 600, 0, 600, -1 ,1);      // modo de projecao ortogonal
} 

void display(void)
{
  int i;
  glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // NOTHING = Preenchido
  glColor3f (0.0, 1.0, 0.0);                  // cor da linha
  glLineWidth(4.0); 
  glBegin(GL_TRIANGLE_STRIP);
  glVertex2i(0, 50); glVertex2i(100, 150); glVertex2i(50, 200); 
				  						   glVertex2i(100, 250);

  
  

  glEnd();
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:  // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}




