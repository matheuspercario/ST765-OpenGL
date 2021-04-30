#include<stdlib.h>
#include<GL/glut.h>

/**
 *  Medidas dadas em Metros
 */
#define CHAO_ALTURA 0.1
#define PISTA_TRANSLACAO_Y 0.0
#define PISTA_TRANSLACAO_Z 0.0 
#define PISTA_ESCALONAMENTO_X 45.0
#define PISTA_ESCALONAMENTO_Y 0.2
#define GALPAO_ESCALONAMENTO_X 150.0
#define GALPAO_ESCALONAMENTO_Y 50.5
#define GALPAO_ESCALONAMENTO_Z 130.0
#define GALPAO_TRANSLACAO_X -500
#define GALPAO_ESPACAMENTO 20
#define PORTOES_ESCALONAMENTO_X 200.0
#define PORTOES_ESCALONAMENTO_Y 70.0
#define PORTOES_ESCALONAMENTO_Z 1000.0
#define PORTOES_TRANSLACAO_X 600.0
#define TORRE_CONTROLE_BASE_RAIO 30
#define TORRE_CONTROLE_BASE_ALTURA 100
#define TORRE_CONTROLE_BASE_SLICES 10
#define TORRE_CONTROLE_BASE_STACKS 10
#define TORRE_CONTROLE_BASE_TRANSLACAO_X GALPAO_ESCALONAMENTO_X
#define TORRE_CONTROLE_BASE_TRANSLACAO_Z 0.0 

static int rotx = 0;
static int roty = 0;

// TODO: torre de controle e portıes de embarque

/**
 * Desenha a torre de controle
 *
 * @param recebe a quantidade de galpoes criados para gerar espaÁamento
 */
void desenhar_torre_controle(float quantidade_galpoes){
  glPushMatrix();

  float t_z = - ((quantidade_galpoes/2) * (GALPAO_ESCALONAMENTO_Z * 2));

  glRotatef ((GLfloat) 90, 0.0, 0.0, 0.0);
  //glTranslatef (TORRE_CONTROLE_BASE_TRANSLACAO_X, CHAO_ALTURA + (TORRE_CONTROLE_BASE_ALTURA/2), t_z);
  glutWireCylinder(TORRE_CONTROLE_BASE_RAIO,TORRE_CONTROLE_BASE_ALTURA,TORRE_CONTROLE_BASE_SLICES,TORRE_CONTROLE_BASE_STACKS);

  glPopMatrix();
}


/**
 * Desenha os portıes onde haver· cada port„o de embarque *
 */
void desenhar_portoes(){
  glPushMatrix();

  glTranslatef (PORTOES_TRANSLACAO_X, CHAO_ALTURA + (PORTOES_ESCALONAMENTO_Y/2), 0.0);
  glScalef (PORTOES_ESCALONAMENTO_X, PORTOES_ESCALONAMENTO_Y, PORTOES_ESCALONAMENTO_Z);
  glutWireCube (1.0);

  glPopMatrix();
}

/**
 * Desenha um galp√£o de acordo com os par√¢metros
 * 
 * @param t_x faz a transla√ß√£o do eixo X
 * @param t_y faz a transla√ß√£o do eixo Y
 * @param t_z faz a transla√ß√£o do eixo Z
 */
void desenhar_galpao(int quantidade_galpoes, int galpao){
  glPushMatrix();

  // transla√ß√£o de Y
  float t_z =  ((GALPAO_ESCALONAMENTO_Z + GALPAO_ESPACAMENTO) * galpao) - ((quantidade_galpoes/2) * GALPAO_ESCALONAMENTO_Z);

  glTranslatef (GALPAO_TRANSLACAO_X, CHAO_ALTURA + (GALPAO_ESCALONAMENTO_Y/2), t_z);
  glScalef (GALPAO_ESCALONAMENTO_X, GALPAO_ESCALONAMENTO_Y, GALPAO_ESCALONAMENTO_Z);
  glutWireCube (1.0);

  glPopMatrix();
}

/**
 * Desenha uma pista de acordo com os par√¢metros
 * 
 * @param t_x faz a transla√ß√£o do eixo X
 * @param e_z faz o escalonamento do eixto Z
 */
void desenhar_pista(float t_x, float e_z){
  glPushMatrix();

  glTranslatef (t_x, PISTA_TRANSLACAO_Y, PISTA_TRANSLACAO_Z);
  glScalef (PISTA_ESCALONAMENTO_X, PISTA_ESCALONAMENTO_Y, e_z);
  glutWireCube (1.0);

  glPopMatrix();
}

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  glRotatef ((GLfloat) rotx, 1.0, 0.0, 0.0);
  glRotatef ((GLfloat) roty, 0.0, 1.0, 0.0);
  
  // congonhas tem duas pistas:
  // 1940x45 e 1495x45  
  desenhar_pista(-100.0,1940.0);
  desenhar_pista(100.0,1495.0);

  // galp√µes/hagares
  int 
  	qtd_galpoes = 5,
  	i;  
  for(i= 0; i < qtd_galpoes;i++){
  	desenhar_galpao(qtd_galpoes,i);
  }  
  // Portıes onde ficar„o os portıes de embarque
  desenhar_portoes();
  
  desenhar_torre_controle(qtd_galpoes);

  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 3000.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, -200.0, -1500.0);
}
void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 'r':
    roty = (roty + 5) % 360;
    glutPostRedisplay();
    break;
  case 'R':
    roty = (roty - 5) % 360;
    glutPostRedisplay();
    break;
   case 'x':
    rotx = (rotx + 5) % 360;
    glutPostRedisplay();
    break;
  case 'X':
    rotx = (rotx - 5) % 360;
    glutPostRedisplay();
    break;
  case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
